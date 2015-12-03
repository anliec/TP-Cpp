//
// Created by Edern Haumont on 23/11/2015.
//

#include <algorithm>
#include "DataManager.h"
#include "config.h"

using namespace std;


int DataManager::LoadLogFile(const std::string &logFilePath)
{
    ifstream logFile(logFilePath, ios::in);  // on ouvre le fichier en lecture
    if(!logFile)
    {
        cerr << "erreur d'ouverture de fichier";
        return 1;
    }
    else
    {
        while(!logFile.eof())
        {
            std::string ip;
            tm time;
            unsigned char httpCode;
            unsigned sizeTransfered;
            std::string browser;
            std::string logname;
            std::string pseudo;
            std::string request;
            int GMT;
            string unusedBuffer;
            string timeBuffer;
            string protocolRequest;
            string refererRequest;
            string destination;

            logFile >> ip >> logname >> pseudo >> timeBuffer >> request >> refererRequest >> protocolRequest >>
                    httpCode >> sizeTransfered >> destination;
            request.append(refererRequest);
            request.append(protocolRequest);

            time.tm_mday = atoi(timeBuffer.substr(1,2).c_str());
            string Month [] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
            for(int i=0;i<12;i++)
            {
                if (Month[i].compare(timeBuffer.substr(4,6))==0)
                {
                    time.tm_mon = i;
                }
            }
            time.tm_year = atoi(timeBuffer.substr(8,11).c_str());
            time.tm_hour = atoi(timeBuffer.substr(13,14).c_str());
            time.tm_min = atoi(timeBuffer.substr(16,17).c_str());
            time.tm_sec = atoi(timeBuffer.substr(19,20).c_str());
            GMT = atoi(timeBuffer.substr(23,26).c_str());
            GMT *= (timeBuffer.substr(22,22) == "-") ? -1 : 1;

            getline(logFile, unusedBuffer, '"');
            getline(logFile, browser, '"');

            LogOtherInfos other(ip,time,httpCode,sizeTransfered,browser,logname,pseudo,request);

            add(refererRequest, destination, time.tm_hour, httpCode, other);
        }
    }
    return 0;
}
int DataManager::Request(bool optionT, int tHour, bool optionE, bool optionG, const std::string &outputFile)
{
    initGraphFile(outputFile);

    int hourMin=0,hourMax=23;
    if(optionT)
    {
        hourMin = tHour;
        hourMax = tHour+1;
    }

    std::vector< pageAndHits > pageHit;

    for (int c = 0; c < 2; c++)
    {
        for(dataFromLevel::iterator f=data[c].begin() ; f!=data[c].end() ; f++)
        {
            addNodeToGraph(f->first);
            int numberOfHitsByPage=0;

            for(dataDestinationLevel::iterator d=f->second.begin() ; d!=f->second.end() ; d++)
            {
                int numberOfHitsByReferrer = 0;
                for (int h=hourMin ; h<hourMax ; h++)
                {
                    numberOfHitsByReferrer += d->second[h].size();
                }
                addLinkToGraph(f->first,d->first,to_string(numberOfHitsByReferrer));
                numberOfHitsByPage += numberOfHitsByReferrer;
            }

            pageAndHits tuple(f->first, numberOfHitsByPage);
            pageHit.push_back(tuple);
        }
    }



    std::sort(pageHit.begin(),pageHit.end(),&compareDateAndHits);

    return 0;
}

int DataManager::add(const std::string &referrer, const std::string &destination, unsigned char hour, int httpCode, const LogOtherInfos &other)
{
    int indexHttpCode = (httpCode/100)-1;

    //try to add the referrer level to the destination level (if he already exist does nothing)
    dataDestinationLevel tempDestLevelTree;
    std::pair<std::string,dataDestinationLevel> insertionPairDest(destination, tempDestLevelTree);
    data[indexHttpCode].insert(insertionPairDest);

    //try to add the hour level to the referrer level (if he already exist does nothing)
    dataDestinationLevel &dataDestLvl = data[indexHttpCode].at(destination);
    dataHourLevel tempHourLevelVector[24];
    std::pair<std::string,dataHourLevel*> insertionPairHour(referrer, tempHourLevelVector);
    dataDestLvl.insert(insertionPairHour);

    dataDestLvl.at(referrer)[hour].push_back(other);

    return 0;
}

int DataManager::addNodeToGraph(const std::string &nodeName)
{
    if(!graphFileStream)
    {
        std::cerr << "erreur sur le fichier en écriture" << std::endl;
        return FILE_ERROR;
    }
    else
    {
        graphFileStream << transformToNodeName(nodeName) << "[label=\"" << nodeName << "\"];" << endl;
    }
    return 0;
}
int DataManager::addLinkToGraph(const std::string &nodeNameFrom, const std::string &nodeNameTo, const std::string &linkLabel)
{
    if(!graphFileStream)
    {
        std::cerr << "erreur sur le fichier en écriture" << std::endl;
        return FILE_ERROR;
    }
    else
    {
        graphFileStream << transformToNodeName(nodeNameFrom) << " -> " << transformToNodeName(nodeNameTo) << " label=[" << linkLabel << "];" << endl;
    }
    return 0;
}
int DataManager::initGraphFile(const std::string &filePath)
{
    // ouverture en ecriture avec effacement du fichier ouvert
    graphFileStream.open(filePath,ios::out | ios::trunc);
    if(!graphFileStream)
    {
        std::cerr << "erreur d'ouverture de fichier" << std::endl;
        return FILE_ERROR;
    }
    return 0;
}
int DataManager::closeGraphFile()
{
    graphFileStream.close();
    return 0;
}

std::string DataManager::transformToNodeName(const std::string &nonUsableName) const
{
    std::string invalidChar = "/\\: ";
    std::string ret;
    bool add = true;
    for (unsigned i=0; i<nonUsableName.length(); i++)
    {
        for(unsigned n=0 ; n<invalidChar.length() ; n++)
        {
            if(nonUsableName.at(i)==invalidChar.at(n))
            {
                add = false;
                break;
            }
        }
        if(add)
        {
            ret.push_back(nonUsableName.at(i));
        }
    }
    return ret;
}


bool DataManager::compareDateAndHits(const pageAndHits &A, const pageAndHits &B)
{
    return (A.second > B.second) || ((A.second == B.second) && (A.first.compare(B.first)<0));
}

bool DataManager::isNotExcludedDocument(const std::string &pagePath) const
{
    std::string extension = pagePath.substr( pagePath.find_last_of('.'));

    for (int i = 0; i < excludedExtension.size(); ++i) {
        if(extension.compare(excludedExtension.at(i))==0)
        {
            return false;
        }
    }

    return true;
}

DataManager::DataManager() {
    ifstream extensionFile (EXTENSION_FILE,ios::in);
    std::string extension;
    while(getline(extensionFile,extension))
    {
        excludedExtension.push_back(extension);
    }
    extensionFile.close();
}

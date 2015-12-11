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
        std::cerr << "erreur lors de l'ouverture du fichier de log: " << logFilePath << std::endl;
        return 1;
    }
    else
    {
        string logLine;

        string ip;
        tm time;
        unsigned int httpCode;
        string sizeTransfered;
        unsigned int sizeTransferedValue;
        string browser;
        string logname;
        string pseudo;
        string request;
        int GMT;
        string unusedBuffer;
        string dateBuffer, GMTBuffer;
        string protocolRequest;
        string URLRequest;
        string refferer;

        int numberOfLine = 0;

        while(getline(logFile,logLine))
        {
            numberOfLine++;
            try
            {
                std::stringstream ss(logLine);
                ss >> ip >> logname >> pseudo >> dateBuffer >> GMTBuffer >> request;
                string bufferString;
                getline(ss, bufferString, '"');// >> URLRequest >> protocolRequest;
                int lastSpace = bufferString.find_last_of(" ");
                URLRequest = bufferString.substr(0,lastSpace);
                protocolRequest = bufferString.substr(lastSpace+1, bufferString.length()-lastSpace-1);
                ss >> httpCode >> sizeTransfered >> refferer;
                if(sizeTransfered.compare("-") ==0)
                {
                    sizeTransferedValue = 0;
                }
                else
                {
                    sizeTransferedValue = atoi(sizeTransfered.c_str());
                }
                request.append(" ");
                request.append(URLRequest);
                request.append(" ");
                request.append(protocolRequest);

                time.tm_mday = atoi(dateBuffer.substr(1,2).c_str());
                string Month [] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
                for(int i=0;i<12;i++)
                {
                    if (Month[i].compare(dateBuffer.substr(4,3))==0)
                    {
                        time.tm_mon = i;
                        break;
                    }
                }
                time.tm_year = atoi(dateBuffer.substr(8,4).c_str());
                time.tm_hour = atoi(dateBuffer.substr(13,2).c_str());
                time.tm_min = atoi(dateBuffer.substr(16,2).c_str());
                time.tm_sec = atoi(dateBuffer.substr(19,2).c_str());
                GMT = atoi(GMTBuffer.substr(1,4).c_str()); // /100 ? ( 0200 -> 2h)
                GMT *= (GMTBuffer.substr(0,1) == "-") ? -1 : 1;
                if(refferer.length()>32 && refferer.substr(1,32).compare("http://intranet-if.insa-lyon.fr/")==0)
                {
                    refferer = refferer.substr(32);
                }
                refferer = refferer.substr(0,refferer.size()-1);

                getline(ss, unusedBuffer, '"');
                getline(ss, browser, '"');

                LogOtherInfos other(ip,time,httpCode,sizeTransferedValue,browser,logname,pseudo,request);
                add(refferer, URLRequest, time.tm_hour, httpCode, other);
            }
            catch (exception e)
            {
                std::cerr << e.what() << " when reading the log file" << std::endl;
            }
        }
        std::cout << "nombre de ligne lue: " << numberOfLine << " end of file= " << logFile.eof() << std::endl;
    }



    return 0;
}
int DataManager::Request(bool optionT, int tHour, bool optionE, bool optionG, const std::string &outputFile)
{
    if(optionG)
    {
        initGraphFile(outputFile);
    }


    int hourMin=0,hourMax=24;
    if(optionT)
    {
        hourMin = tHour;
        hourMax = tHour+1;
    }

    std::vector< pageAndHits > pageHit;

    for (int c = 0; c < 1; c++)
    {
        if(data[c] != nullptr)
        {
            //iterate through the from node:
            for(dataFromLevel::iterator f=data[c]->begin() ; f!=data[c]->end() ; ++f)
            {
                //option -e filter: if the option is activated then only select the specified extension
                if( !optionE || isNotExcludedDocument(f->first) )
                {
                    if(optionG)
                    {
                        addNodeToGraph(f->first);
                    }
                    int numberOfHitsByPage=0;

                    //iterate through the referrer branches:
                    for(dataDestinationLevel::iterator d=f->second->begin() ; d!=f->second->end() ; ++d)
                    {
                        int numberOfHitsByReferrer = 0;
                        for (int h=hourMin ; h<hourMax ; h++)
                        {
                            numberOfHitsByReferrer += d->second[h].size();
                            /*numberOfHitsByReferrer += d->second[h].size();
                            std::cerr << "to " << f->first << " from " << d->first << " at h=" << h << " hits: " << d->second[h].size();
                            std::cerr << " or " << data[c].at(f->first).at(d->first)[h].size() << std::endl;*/
                        }
                        if(optionG)
                        {
                            addLinkToGraph(f->first,d->first,to_string(numberOfHitsByReferrer));
                        }
                        numberOfHitsByPage += numberOfHitsByReferrer;
                    }
                    pageAndHits tuple(f->first, numberOfHitsByPage);
                    pageHit.push_back(tuple);
                }
            }
        }
    }

    if(optionG)
    {
        closeGraphFile();
    }

    std::sort(pageHit.begin(),pageHit.end(),&compareDateAndHits);

    for (int i=0 ; i<10 && i<pageHit.size() ; i++)
    {
        std::cout << pageHit.at(i).first << " (" << pageHit.at(i).second << " hits)" << std::endl;
    }

    return 0;
}

int DataManager::add(const std::string &referrer, const std::string &destination, unsigned int hour, unsigned int httpCode, const LogOtherInfos &other)
{
    unsigned int indexHttpCode = (httpCode/200)-1;

    //dataFromLevel* destinationMap;
    dataDestinationLevel* referrerMap;

    if(data[indexHttpCode] == nullptr)
    {
        data[indexHttpCode] = new dataFromLevel();
    }

    //try to add the referrer level to the destination level (if he already exist does nothing)
    if(data[indexHttpCode]->find(destination) == data[indexHttpCode]->end())
    {
        referrerMap = new dataDestinationLevel();
        std::pair<std::string,dataDestinationLevel*> insertionPairDest(destination, referrerMap);
        data[indexHttpCode]->insert(insertionPairDest);
    }
    else
    {
        referrerMap = data[indexHttpCode]->at(destination);
    }

    //try to add the hour level to the referrer level (if he already exist does nothing)
    if(referrerMap->find(referrer) == referrerMap->end())
    {
        dataHourLevel * tempHourLevelVector = new dataHourLevel[24];
        for (int i = 0; i < 24; i++)
        {
            dataHourLevel temp;
            tempHourLevelVector[i] = temp;
        }
        std::pair<std::string,dataHourLevel*> insertionPairHour(referrer, tempHourLevelVector);
        referrerMap->insert(insertionPairHour);
    }

    //referrerIterator->second[hour].push_back(other);
    dataHourLevel * hourLevel = referrerMap->at(referrer);
    hourLevel[hour].push_back(other);

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
        graphFileStream << "       " << transformToNodeName(nodeName) << " [label=\"" << nodeName << "\"];" << endl;
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
        graphFileStream << "       " << transformToNodeName(nodeNameFrom) << " -> " << transformToNodeName(nodeNameTo) << " [label=" << linkLabel << "];" << endl;
    }
    return 0;
}
int DataManager::initGraphFile(const std::string &filePath)
{
    // ouverture en ecriture avec effacement du fichier ouvert
    graphFileStream.open(filePath,ios::out | ios::trunc);
    if(!graphFileStream)
    {
        std::cerr << "erreur lors de l'ouverture du fichier: " << filePath << std::endl;
        return FILE_ERROR;
    }
    graphFileStream << "digraph {" << std::endl;
    return 0;
}
int DataManager::closeGraphFile()
{
    graphFileStream << "}" << std::endl;
    graphFileStream.close();
    return 0;
}

std::string DataManager::transformToNodeName(const std::string &nonUsableName) const
{
    std::string invalidChar = "/\\:\"'^£$|[](){}#~?&%.=-+*,_ ";
    std::string ret = "nomde";
    bool add;
    for (unsigned i=0; i<nonUsableName.length(); i++)
    {
        add = true;
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
        /*else if(nonUsableName.at(i) == '-')
        {
            ret.append("UnPetitTiret");
        }*/
    }
    return ret;
}


bool DataManager::compareDateAndHits(const pageAndHits &A, const pageAndHits &B)
{
    return (A.second > B.second) || ((A.second == B.second) && (A.first.compare(B.first)<0));
}

bool DataManager::isNotExcludedDocument(const std::string &pagePath) const
{
    if(pagePath.find('.') != string::npos)
    {
        std::string extension = pagePath.substr( pagePath.find_last_of('.'));

        for (int i = 0; i < excludedExtension.size(); ++i) {
            if(extension.compare(excludedExtension.at(i))==0)
            {
                return false;
            }
        }
    }

    return true;
}

DataManager::DataManager() {
    ifstream extensionFile (EXTENSION_FILE);
    for(std::string extension ; std::getline(extensionFile,extension) ; )
    {
        excludedExtension.push_back(extension);
    }
    extensionFile.close();

    for (int i = 0; i < DATA_TAB_SIZE; ++i)
    {
        data[i] = nullptr;
    }
}

DataManager::~DataManager()
{
    for (int c = 0; c < DATA_TAB_SIZE; c++)
    {
        if(data[c] != nullptr)
        {
            //iterate through the from node:
            for(dataFromLevel::iterator f=data[c]->begin() ; f!=data[c]->end() ; ++f)
            {
                //iterate through the referrer branches:
                for(dataDestinationLevel::iterator d=f->second->begin() ; d!=f->second->end() ; ++d)
                {
                    delete [] d->second;
                }
                delete f->second;
            }
            delete data[c];
        }
    }
}

//
// Created by Edern Haumont on 23/11/2015.
//

#include "DataManager.h"

using namespace std;

int DataManager::LoadLogFile(std::string logFilePath)
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
            request += refererRequest + protocolRequest;

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
int DataManager::Request(bool optionT, int tHour, bool optionE, bool optionG, std::string outputFile)
{
    if(optionG)
    {

    }
    else
    {

    }
    return 0;
}
int DataManager::add(std::string referrer, std::string destination, unsigned char hour, int httpCode, LogOtherInfos other)
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
int DataManager::addNodeToGraph(int nodeNumber, string label, ofstream flux)
{
    if(!flux)
    {
        cout << "erreur sur le fichier en écriture" << endl;
        return FILE_ERROR;
    }
    else
    {
        flux << label << ";" << endl;
    }
    return 0;
}
int DataManager::addLinkToGraph(int from, int to, string linkLabel, ofstream flux)
{
    if(!flux)
    {
        cout << "erreur sur le fichier en écriture" << endl;
        return FILE_ERROR;
    }
    else
    {
        flux << from << " -> " << to << " label=[" << linkLabel << "];" << endl;
    }
    return 0;
}
int DataManager::initGraphFile(std::string filePath)
{
    ofstream gFile("path", ios::out | ios::trunc);  // ouverture en ecriture avec effacement du fichier ouvert
    if(!gFile)
    {
        cout << "erreur d'ouverture de fichier" << endl;
        return FILE_ERROR;
    }
    return 0;
}
int DataManager::closeGraphFile()
{
    return 0;
}

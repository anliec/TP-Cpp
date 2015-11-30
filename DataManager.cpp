//
// Created by Edern Haumont on 23/11/2015.
//

#include "DataManager.h"

using namespace std;

int DataManager::LoadLogFile(std::string logFilePath)
{
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

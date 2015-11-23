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
int DataManager::add(std::string referrer, std::string destination, char hour)
{
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

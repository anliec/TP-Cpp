/*************************************************************************
                           DataManager  -  description
                             -------------------
    debut                : 23/11/2015
    copyright            : (C) 2015 by Edern Haumont & Nicolas Six
*************************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>

#include "LogOtherInfos.h"

//-------- Interface of the class DataManager (file DataManager.h) -------
#ifndef TP_CPP_DATAMANAGER_H
#define TP_CPP_DATAMANAGER_H

//------------------------------------------------------------- Constants
const int FILE_ERROR = 80;

//------------------------------------------------------------------------
// What is this class useful ?
//------------------------------------------------------------------------

typedef std::vector< LogOtherInfos > dataHourLevel;
typedef std::map< std::string, dataHourLevel[] > dataDestinationLevel;
typedef std::map< std::string, dataDestinationLevel > dataFromLevel;

class DataManager {

//----------------------------------------------------------------- PUBLIC
public:


//--------------------------------------------------------- Public methods
    int LoadLogFile(std::string logFilePath);
    int Request(bool optionT=false,int tHour=-1, bool optionE=false, bool optionG=false, std::string outputFile="");


//--------------------------------------------- Constructors - destructors

//-------------------------------------------------------- Private methods
private:
    int add(std::string referrer, std::string destination, unsigned char hour, int httpCode, LogOtherInfos other);
    int addNodeToGraph(int nodeNumber, std::string label, std::ofstream flux);
    int addLinkToGraph(int from, int to, std::string linkLabel, std::ofstream flux);

    int initGraphFile(std::string filePath);
    int closeGraphFile();

//------------------------------------------------------- Private atributs

    std::ofstream graphFileStream;
    dataFromLevel data[4];

};


#endif //TP_CPP_DATAMANAGER_H

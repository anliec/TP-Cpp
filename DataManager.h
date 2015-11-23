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


//------------------------------------------------------------------------
// What is this class useful ?
//------------------------------------------------------------------------
class DataManager {

//----------------------------------------------------------------- PUBLIC
public:


//--------------------------------------------------------- Public methods
    int LoadLogFile(std::string logFilePath);
    int Request(bool optionT=false,int tHour=-1, bool optionE=false, bool optionG=false, std::string outputFile="");


//--------------------------------------------- Constructors - destructors

//-------------------------------------------------------- Private methods
private:
    int add(std::string referrer, std::string destination, char hour);
    int addNodeToGraph(int nodeNumber, std::string label);
    int addLinkToGraph(int from, int to, std::string linkLabel);

    int initGraphFile(std::string filePath);
    int closeGraphFile();

//------------------------------------------------------- Private atributs

    std::ofstream graphFileStream;
    std::map< std::map< std::vector< LogOtherInfos >[24], std::string >, std::string > data;

};


#endif //TP_CPP_DATAMANAGER_H

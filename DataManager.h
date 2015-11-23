/*************************************************************************
                           DataManager  -  description
                             -------------------
    debut                : 23/11/2015
    copyright            : (C) 2015 by Edern Haumont & Nicolas Six
*************************************************************************/
#include <string>

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
    int Add(std::string referrer, std::string destination, char hour);
    int mostVisited();
    int mostVisited(char hour);
    int genGraphViz();

//--------------------------------------------- Constructors - destructors

//-------------------------------------------------------- Private methods
};


#endif //TP_CPP_DATAMANAGER_H

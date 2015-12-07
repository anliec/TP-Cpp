/*************************************************************************
                           DataManager  -  description
                             -------------------
    debut                : 23/11/2015
    copyright            : (C) 2015 by Edern Haumont & Nicolas Six
*************************************************************************/

#include <ctime>
#include <stdlib.h>
#include <string>
#include <iostream>


//-------- Interface of the class DataManager (file DataManager.h) -------
#ifndef TP_CPP_LOGOTHERINFOS_H
#define TP_CPP_LOGOTHERINFOS_H

//------------------------------------------------------------- Constants


//------------------------------------------------------------------------
// What is this class useful ?
//------------------------------------------------------------------------

class LogOtherInfos
{
//----------------------------------------------------------------- PUBLIC
public:
//--------------------------------------------------------- Public methods
//-------------------------------------------------------------- Overloads
    /*std::istream &operator>>(std::istream  &input);*/
//--------------------------------------------- Constructors - destructors
    LogOtherInfos();
    LogOtherInfos(const std::string &logIp,const tm &logTime, unsigned int logCode, const unsigned &logSize,
                  const std::string &logBrowser, const std::string &logLogname, const std::string &logPseudo,
                  const std::string &logRequest);
//---------------------------------------------------------------- PRIVATE
private:
//-------------------------------------------------------- Private methods

//------------------------------------------------------- Private atributs
    std::string ip;
    tm time;
    unsigned int httpCode;
    unsigned sizeTransfered;
    std::string Browser;
    std::string logname;
    std::string pseudo;
    std::string request;
    int GMT;
};


#endif //TP_CPP_LOGOTHERINFOS_H

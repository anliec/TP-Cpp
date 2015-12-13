/*************************************************************************
                           LogOtherInfos  -  description
                             -------------------
    debut                : 23/11/2015
    copyright            : (C) 2015 by Edern Haumont & Nicolas Six
*************************************************************************/

#include <ctime>
#include <stdlib.h>
#include <string>
#include <iostream>


//------ Interface of the class LogOtherInfos (file LogOtherInfos.h) -----
#ifndef TP_CPP_LOGOTHERINFOS_H
#define TP_CPP_LOGOTHERINFOS_H

//-------------------------------------------------------------- Constants


//------------------------------------------------------------------------
// This class contains all non classification informations
//------------------------------------------------------------------------

class LogOtherInfos
{
//----------------------------------------------------------------- PUBLIC
public:
//--------------------------------------------- Constructors - destructors
    LogOtherInfos();
    LogOtherInfos(const std::string &logIp,const tm &logTime,const unsigned int &logCode, const unsigned &logSize,
                  const std::string &logBrowser, const std::string &logLogname, const std::string &logPseudo,
                  const std::string &logRequest, const int &logGMT);
//------------------------------------------------------------------Getter
    std::string & getRequest();
//---------------------------------------------------------------- PRIVATE
private:
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

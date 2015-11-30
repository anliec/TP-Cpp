/*************************************************************************
                           DataManager  -  description
                             -------------------
    debut                : 23/11/2015
    copyright            : (C) 2015 by Edern Haumont & Nicolas Six
*************************************************************************/

#include <ctime>
#include <string.h>

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

//--------------------------------------------- Constructors - destructors
    LogOtherInfos();
    LogOtherInfos(std::string logIp, time_t logTime, unsigned char logCode, unsigned logSize, std::string logBrowser);
//---------------------------------------------------------------- PRIVATE
private:
//-------------------------------------------------------- Private methods

//------------------------------------------------------- Private atributs
    std::string ip;
    time_t time;
    unsigned char httpCode;
    unsigned sizeTransfered;
    std::string Browser;
};


#endif //TP_CPP_LOGOTHERINFOS_H

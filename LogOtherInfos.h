/*************************************************************************
                           DataManager  -  description
                             -------------------
    debut                : 23/11/2015
    copyright            : (C) 2015 by Edern Haumont & Nicolas Six
*************************************************************************/

#include <ctime>
#include <string>

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

//--------------------------------------------- Constructors - destructors
    LogOtherInfos(unsigned ipInLog, time_t logTime, unsigned char httpReturnCode, unsigned sizeTransferred, std::string BrowserInfo);
//---------------------------------------------------------------- PRIVATE
private:
//-------------------------------------------------------- Private methods

//------------------------------------------------------- Private atributs
    unsigned ip;
    time_t time;
    unsigned char httpCode;
    unsigned sizeOfFileTransferred;
    std::string clientInfo;
};


#endif //TP_CPP_LOGOTHERINFOS_H

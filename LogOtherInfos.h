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
#include <bits/stringfwd.h>
#include <bits/basic_string.h>

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
    std::istream &operator>>(std::istream  &input);
//--------------------------------------------- Constructors - destructors
    LogOtherInfos();
    /*LogOtherInfos(const std::string &logIp,const time_t &logTime, unsigned char logCode, const unsigned &logSize,
                  const std::string &logBrowser);*/
//---------------------------------------------------------------- PRIVATE
private:
//-------------------------------------------------------- Private methods

//------------------------------------------------------- Private atributs
    std::string ip;
    tm time;
    unsigned char httpCode;
    unsigned sizeTransfered;
    std::string Browser;
    std::string logname;
    std::string pseudo;
    std::string request;
    int GMT;
};


#endif //TP_CPP_LOGOTHERINFOS_H

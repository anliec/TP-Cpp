/*************************************************************************
                           LogOtherInfos  -  description
                             -------------------
    begin                : 23/11/2015
    copyright            : (C) 2015 by Edern Haumont & Nicolas Six
*************************************************************************/

//- Realisation of the class LogOtherInfos (file LogOtherInfos) -

//---------------------------------------------------------------- INCLUDE

//------------------------------------------------------- Personal include
#include "LogOtherInfos.h"

using namespace std;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------------- Constructors
LogOtherInfos::LogOtherInfos()
{
}

LogOtherInfos::LogOtherInfos(const std::string &logIp,const tm &logTime,const unsigned int &logCode, const unsigned &logSize,
                             const std::string &logBrowser, const std::string &logLogname, const std::string &logPseudo,
                             const std::string &logRequest, const int &logGMT):
                    ip(logIp),
                    time(logTime),
                    httpCode(logCode),
                    sizeTransfered(logSize),
                    Browser(logBrowser),
                    logname(logLogname),
                    pseudo(logPseudo),
                    request(logRequest),
                    GMT(logGMT)
{
}

//getter
std::string & LogOtherInfos::getRequest() {
    return request;
}

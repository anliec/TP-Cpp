//
// Created by nicolas on 23/11/15.
//

#include "LogOtherInfos.h"

using namespace std;

LogOtherInfos::LogOtherInfos()
{
}

LogOtherInfos::LogOtherInfos(string logIp, time_t logTime, unsigned char logCode, unsigned logSize, std::string logBrowser):
                    ip(logIp),
                    time(logTime),
                    httpCode(logCode),
                    sizeTransfered(logSize),
                    Browser(logBrowser)
{
}

LogOtherInfos::
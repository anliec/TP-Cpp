//
// Created by nicolas on 23/11/15.
//

#include "LogOtherInfos.h"
LogOtherInfos::LogOtherInfos(unsigned ipInLog,
                             time_t logTime,
                             unsigned char httpReturnCode,
                             unsigned sizeTransferred,
                             std::string BrowserInfo):
                    ip(ipInLog),
                    time(logTime),
                    httpCode(httpReturnCode),
                    sizeOfFileTransferred(sizeTransferred),
                    clientInfo(BrowserInfo)
{

}

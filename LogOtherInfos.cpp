//
// Created by nicolas on 23/11/15.
//

#include "LogOtherInfos.h"

using namespace std;

LogOtherInfos::LogOtherInfos()
{
}

//no more used
LogOtherInfos::LogOtherInfos(const std::string &logIp,const tm &logTime, unsigned int logCode, const unsigned &logSize,
                             const std::string &logBrowser, const std::string &logLogname, const std::string &logPseudo,
                             const std::string &logRequest):
                    ip(logIp),
                    time(logTime),
                    httpCode(logCode),
                    sizeTransfered(logSize),
                    Browser(logBrowser),
                    logname(logLogname),
                    pseudo(logPseudo),
                    request(logRequest)
{
}

/*std::istream &LogOtherInfos::operator>>(std::istream &input) {
    string unusedBuffer;
    string timeBuffer;
    string protocolRequest;

    input >> ip >> logname >> pseudo >> timeBuffer >> request >> protocolRequest >> httpCode >> sizeTransfered >>
            unusedBuffer;
    request += protocolRequest;

    time.tm_mday = atoi(timeBuffer.substr(1,2).c_str());
    string Month [] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    for(int i=0;i<12;i++)
    {
        if (Month[i].compare(timeBuffer.substr(4,6))==0)
        {
            time.tm_mon = i;
        }
    }
    time.tm_year = atoi(timeBuffer.substr(8,11).c_str());
    time.tm_hour = atoi(timeBuffer.substr(13,14).c_str());
    time.tm_min = atoi(timeBuffer.substr(16,17).c_str());
    time.tm_sec = atoi(timeBuffer.substr(19,20).c_str());
    GMT = atoi(timeBuffer.substr(23,26).c_str());
    GMT *= (timeBuffer.substr(22,22) == "-") ? -1 : 1;

    getline(input, unusedBuffer, '"');
    getline(input, Browser, '"');
    return input;
}*/

//
// Created by danim on 01/03/2020.
//

#include "TotalTagSender.h"

#include <cpr/cpr.h>
#include <ctime>
#include <chrono>
#include <time.h>
#include <iostream>

using namespace std::chrono;

TotalTagSender::TotalTagSender(string& url, int readerId)
:
_url(string("http://") + url + ":3215"),
_readerId(readerId)
{
}

TotalTagSender::~TotalTagSender()
{
}

bool TotalTagSender::AddReadTag(TagInfo& tagInfo)
{
    char dtStr[1024];

    time_t dateTime = system_clock::to_time_t(tagInfo.DateTime);
    tm tm = *localtime(&dateTime);

    strftime(dtStr, sizeof(dtStr), "%Y-%m-%dT%H:%M:%S", &tm);
    string dateTimeStr(dtStr);

    auto r = cpr::Get(cpr::Url{_url + "/AddReadTag"},
                      cpr::Parameters{
                              {"Epc", tagInfo.Epc},
                              {"AntennaPortNumber", to_string(tagInfo.AntennaPort)},
                              {"PeakRssiInDbm", to_string(tagInfo.Rssi)},
                              {"ReaderType", "6"},
                              {"DateTime", dateTimeStr}
    });

    return r.status_code == 200;
}

int TotalTagSender::AddReadTag(vector<TagInfo>& tagInfos)
{
    auto count = 0;
    for (int i = 0; i < tagInfos.size(); ++i) {
        if (AddReadTag(tagInfos[i])) {
            ++count;
        }
    }

    return count;
}
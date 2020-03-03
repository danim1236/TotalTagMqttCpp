//
// Created by danim on 01/03/2020.
//

#include "TotalTagSender.h"

#include <cpr/cpr.h>
#include <ctime>
#include <chrono>
#include <time.h>

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

void TotalTagSender::AddReadTag(TagInfo& tagInfo)
{
    char dtStr[1024];

    time_t dateTime = system_clock::to_time_t(tagInfo.DateTime);
    tm tm = *localtime(&dateTime);

    strftime(dtStr, sizeof(dtStr), "%Y-%m-%dT%H:%M:%S", &tm);

    auto r = cpr::Get(cpr::Url{_url},
                      cpr::Parameters{
                              {"Epc", tagInfo.Epc},
                              {"AntennaPortNumber", tagInfo.AntennaPort},
                              {"PeakRssiInDbm", tagInfo.Rssi},
                              {"ReaderType", "6"},
                              {"DateTime", dtStr}});
}

void TotalTagSender::AddReadTag(vector<TagInfo>& tagInfos)
{
    for (int i = 0; i < tagInfos.size(); ++i) {
        AddReadTag(tagInfos[i]);
    }
}
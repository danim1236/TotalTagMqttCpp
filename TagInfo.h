//
// Created by danim on 01/03/2020.
//

#ifndef TOTALTAGMQTTDOCKER_TAGINFO_H
#define TOTALTAGMQTTDOCKER_TAGINFO_H

#include <string>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct TagInfo
{
    bool Ok;
    time_point<system_clock> DateTime;
    string Epc;
    int AntennaPort;
    double Rssi;
    double Phase;

    TagInfo(string& epc, int antennaPort, double rssi, double phase)
    :
    Ok(true),
    DateTime(system_clock::now()),
    Epc(epc),
    AntennaPort(antennaPort),
    Rssi(rssi),
    Phase(phase)
    {
    }

    TagInfo(string& epc, int antennaPort, double rssi)
    :
    TagInfo(epc, antennaPort, rssi, 0)
    {
    }

    TagInfo()
    :
    Ok(false)
    {
    }

    time_t GetDateTime()
    {
        return system_clock::to_time_t(DateTime);
    }
};


#endif //TOTALTAGMQTTDOCKER_TAGINFO_H

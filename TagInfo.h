//
// Created by danim on 01/03/2020.
//

#ifndef TOTALTAGMQTTDOCKER_TAGINFO_H
#define TOTALTAGMQTTDOCKER_TAGINFO_H

#include <string>
#include <ctime>
#include <chrono>

using namespace std;

struct TagInfo
{
    time_t DateTime;
    string Epc;
    int AntennaPort;
    double Rssi;
    double Phase;

    TagInfo(string& epc, int antennaPort, double rssi, double phase)
    :
    DateTime(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())),
    Epc(epc),
    AntennaPort(antennaPort),
    Rssi(rssi),
    Phase(phase)
    {
    }
};


#endif //TOTALTAGMQTTDOCKER_TAGINFO_H

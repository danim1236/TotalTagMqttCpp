//
// Created by danim on 01/03/2020.
//

#ifndef TOTALTAGMQTTDOCKER_TAGINFO_H
#define TOTALTAGMQTTDOCKER_TAGINFO_H

#include <string>

using namespace std;

struct TagInfo
{
    string Epc;
    int AntennaPort;
    double Rssi;
    double Phase;

    TagInfo(string& epc, int antennaPort, double rssi, double phase)
    :
    Epc(epc),
    AntennaPort(antennaPort),
    Rssi(rssi),
    Phase(phase)
    {
    }
};


#endif //TOTALTAGMQTTDOCKER_TAGINFO_H

//
// Created by danim on 01/03/2020.
//

#ifndef TOTALTAGMQTTDOCKER_CONFIG_H
#define TOTALTAGMQTTDOCKER_CONFIG_H

#include <string>
#include <bits/unique_ptr.h>

using namespace std;

struct Config
{
    string MiddlewareUrl;
    int ReaderId;

    string BrokerUrl;
    string ClientId;
    string Topic;
};


#endif //TOTALTAGMQTTDOCKER_CONFIG_H

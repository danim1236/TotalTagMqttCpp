//
// Created by danim on 01/03/2020.
//

#ifndef TOTALTAGMQTTDOCKER_MQTTCLIENT_H
#define TOTALTAGMQTTDOCKER_MQTTCLIENT_H

#include <string>
#include <vector>

#include "MessageCache.h"

using namespace std;

class MqttClient
{
public:
    MqttClient(string clientId, vector<string> topics);
    MqttClient(string clientId, string topic);

    ~MqttClient();

    bool Start();
    bool Stop();

    string GetNextMessage();

    void SetMessageCache(MessageCache messageCache);
};

#endif //TOTALTAGMQTTDOCKER_MQTTCLIENT_H

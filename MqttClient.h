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
    MqttClient(string& brokerUrl, string& clientId, vector<string>& topics, MessageCache& messageCache);
    MqttClient(string& brokerUrl, string& clientId, string& topic, MessageCache& messageCache);

    ~MqttClient();

    bool Start();
    bool Stop();

private:
    string _brokerUrl;
    string _clientId;
    vector<string> _topics;
    MessageCache& _messageCache;
};

#endif //TOTALTAGMQTTDOCKER_MQTTCLIENT_H

//
// Created by danim on 01/03/2020.
//

#ifndef TOTALTAGMQTTDOCKER_MQTTCLIENT_H
#define TOTALTAGMQTTDOCKER_MQTTCLIENT_H

#include <string>
#include <vector>

#include <MQTTClient.h>

#include "TagInfoCache.h"
#include "MessageParser.h"
#include "EventManager.h"

using namespace std;

class MqttClient
{
public:
    MqttClient(string& brokerUrl, string& clientId, vector<string>& topics, TagInfoCache& messageCache);
    MqttClient(string& brokerUrl, string& clientId, string& topic, TagInfoCache& messageCache);

    ~MqttClient();

    bool Start();
    bool Stop();

private:
    string _brokerUrl;
    string _clientId;
    vector<string> _topics;
    MessageParser _messageParser;
    EventManager _eventManager;
    TagInfoCache& _messageCache;

    MQTTClient _client;

    static MqttClient *Instance;

    static int OnMessage(void *context, char *topicName, int topicLen, MQTTClient_message *message);

    vector<string> BuildTopics(string &basicString);
};

#endif //TOTALTAGMQTTDOCKER_MQTTCLIENT_H

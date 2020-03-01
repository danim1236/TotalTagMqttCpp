//
// Created by danim on 01/03/2020.
//

#include "MqttClient.h"

MqttClient::MqttClient(string& brokerUrl, string& clientId, vector<string>& topics, MessageCache &messageCache)
:
_brokerUrl(brokerUrl),
_clientId(clientId),
_topics(topics),
_messageCache(messageCache)
{
}

MqttClient::MqttClient(string& brokerUrl, string& clientId, string& topic, MessageCache &messageCache)
:_brokerUrl(brokerUrl),
_clientId(clientId),
_topics(),
_messageCache(messageCache)
{
    _topics.push_back(string(topic));
}

MqttClient::~MqttClient() {

}

bool MqttClient::Start() {
    return false;
}

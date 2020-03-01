//
// Created by danim on 01/03/2020.
//

#include "MqttClient.h"

MqttClient *MqttClient::Instance = nullptr;

MqttClient::MqttClient(string& brokerUrl, string& clientId, vector<string>& topics, MessageCache &messageCache)
:
_brokerUrl(brokerUrl),
_clientId(clientId),
_topics(topics),
_messageCache(messageCache)
{
    Instance = this;
}

MqttClient::MqttClient(string& brokerUrl, string& clientId, string& topic, MessageCache &messageCache)
:_brokerUrl(brokerUrl),
_clientId(clientId),
_topics(),
_messageCache(messageCache)
{
    Instance = this;
    _topics.push_back(string(topic));
}

MqttClient::~MqttClient()
{
    Stop();
}

bool MqttClient::Start()
{
    int rc;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;

    MQTTClient_create(&_client, _brokerUrl.c_str(), _clientId.c_str(), MQTTCLIENT_PERSISTENCE_NONE, NULL);
    MQTTClient_setCallbacks(_client, NULL, NULL, OnMessage, NULL);

    rc = MQTTClient_connect(_client, &conn_opts);

    if (rc != MQTTCLIENT_SUCCESS)
    {
        printf("\n\rFalha na conexao ao broker MQTT. Erro: %d\n", rc);
        exit(-1);
    }

    for (int i = 0; i < _topics.size(); ++i) {
        MQTTClient_subscribe(_client, _topics[i].c_str(), 0);
    }

    return true;
}

bool MqttClient::Stop() {
    return false;
}

int MqttClient::OnMessage(void *context, char *topicName, int topicLen, MQTTClient_message *message)
{
    char* payload = static_cast<char *>(message->payload);

    for (int i = 0; i < Instance->_topics.size(); ++i) {
        if(Instance->_topics[i] == topicName) {
            Instance->_messageCache.AppendMessage(string(payload));
        }
    }

    MQTTClient_freeMessage(&message);
    MQTTClient_free(topicName);
    return 1;
}

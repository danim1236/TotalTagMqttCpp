//
// Created by danim on 01/03/2020.
//

#include "MqttClient.h"

MqttClient *MqttClient::Instance = nullptr;

MqttClient::MqttClient(string& brokerUrl, string& clientId, vector<string>& topics, TagInfoCache& messageCache)
:
_brokerUrl(brokerUrl),
_clientId(clientId),
_topics(topics),
_messageParser(),
_eventManager(messageCache),
_messageCache(messageCache)
{
    Instance = this;
}

MqttClient::MqttClient(string& brokerUrl, string& clientId, string& topic, TagInfoCache& messageCache)
:
_brokerUrl(brokerUrl),
_clientId(clientId),
_topics(vector<string>()),
_messageParser(),
_eventManager(messageCache),
_messageCache(messageCache)
{
    Instance = this;
    _topics.push_back(topic);
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
            TagInfo tagInfo = Instance->_messageParser.ParseMessage(string(payload));
            if (tagInfo.Ok) {
                Instance->_eventManager.AddTagInfo(tagInfo);
            }
        }
    }

    MQTTClient_freeMessage(&message);
    MQTTClient_free(topicName);
    return 1;
}

vector<string> MqttClient::BuildTopics(string &topic)
{
    vector<string> topics(1);
    topics.push_back(topic);
    return topics;
}

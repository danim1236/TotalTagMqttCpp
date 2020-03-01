#include <iostream>
#include <cstring>

#include "Config.h"
#include "Util.h"
#include "TotalTagSender.h"
#include "EventManager.h"
#include "MessageCache.h"
#include "MqttClient.h"

int main()
{
    string options[] = {"None", "MiddlewareUrl", "ReaderId",
                        "BrokerUrl", "ClientId", "Topic"};
    char buffer[1024];

    Config config;
    FILE *fp = fopen("./config.txt", "r");

    if(fp == nullptr)
    {
        fp = fopen("./config.txt", "w");

        fputs("BrokerUrl:broker.hivemq.com\n", fp);
        fputs("ClientId:TOTALTAG\n", fp);
        fputs("Topic:EZR2500_240AC4055EE0\n", fp);
        fclose(fp);
    }

    fp = fopen("./config.txt", "r");
    if ( fp == nullptr) {
        return 1;
    }

    while (!feof(fp)) {
        buffer[0] = 0;
        fgets(buffer, 1024, fp);
        if (strlen(buffer) > 0) {
            string line(buffer);
            if (line.c_str()[line.length() - 1] == '\n') {
                line = line.substr(0, line.length() - 1);
            }
            size_t pos = line.find_first_of(":");
            if(pos != string::npos && pos < line.length() - 1 && pos > 0) {
                string key = trim(line.substr(0, pos));
                string val = trim(line.substr(pos + 1));

                for (int i = 0; i < sizeof(options) / sizeof(string); ++i) {
                    if (key == options[i]) {
                        switch (i) {
                            case 1:
                                config.MiddlewareUrl = val;
                                break;

                            case 2:
                                config.ReaderId = stoi(val);
                                break;

                            case 3:
                                config.BrokerUrl = val;
                                break;

                            case 4:
                                config.ClientId = val;
                                break;

                            case 5:
                                config.Topic = val;
                                break;
                        }
                    }
                }
            }
        }
    }
    fclose(fp);

    TotalTagSender sender(config.MiddlewareUrl, config.ReaderId);
    EventManager eventManager(sender);

    MessageCache messageCache;
    MqttClient mqttClient(config.BrokerUrl, config.ClientId, config.Topic, messageCache);

    mqttClient.Start();

    while (true)
    {
        if (messageCache.GetMessageCount() > 0) {
            string message(messageCache.GetNextMessage());

            cout << message;
        }
    }

    mqttClient.Stop();
    return 0;
}

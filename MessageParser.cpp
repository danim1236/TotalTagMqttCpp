//
// Created by danim on 01/03/2020.
//

#include "MessageParser.h"

#include "Util.h"

MessageParser::MessageParser()
{
}

MessageParser::~MessageParser()
{
}

TagInfo MessageParser::ParseMessage(string message)
{
    if (message.find_first_of("Heartbeat") != string::npos)
    {
        return TagInfo();
    }

    string epc;
    double rssi;
    int antennaPort;

    auto lines = Split(message);

    for (int i = 0; i < lines.size(); ++i) {
        auto line = lines[i];
        if (line[1] == ':') {
            auto key = line[0];
            auto val = line.substr(2);
            switch (key) {
                case 'E':
                    epc = val;
                    break;

                case 'A':
                    antennaPort = stoi(val);
                    break;

                case 'R':
                    rssi = stod(val);
                    rssi /= 100.0;
                    break;
            }
        }
    }

    TagInfo tagInfo(epc, antennaPort, rssi);

    return tagInfo;
}

vector<TagInfo> MessageParser::ParseMessages(vector<string> messages)
{
    vector<TagInfo> tagInfos(messages.size());

    for (int i = 0; i < messages.size(); ++i) {
        TagInfo tagInfo = ParseMessage(messages[i]);
        if (tagInfo.Ok) {
            tagInfos.push_back(tagInfo);
        }
    }

    return tagInfos;
}

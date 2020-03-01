//
// Created by danim on 01/03/2020.
//

#ifndef TOTALTAGMQTTDOCKER_MESSAGEPARSER_H
#define TOTALTAGMQTTDOCKER_MESSAGEPARSER_H

#include <string>
#include <vector>

#include "TagInfo.h"

using namespace std;

class MessageParser
{
public:
    MessageParser();
    ~MessageParser();

    TagInfo ParseMessage(string message);
    vector<TagInfo> ParseMessages(vector<string> messages);
};


#endif //TOTALTAGMQTTDOCKER_MESSAGEPARSER_H

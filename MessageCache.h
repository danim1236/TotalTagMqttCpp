//
// Created by danim on 01/03/2020.
//

#ifndef TOTALTAGMQTTDOCKER_MESSAGECACHE_H
#define TOTALTAGMQTTDOCKER_MESSAGECACHE_H


#include <string>
#include <vector>

using namespace std;

class MessageCache
{
public:
    MessageCache();
    ~MessageCache();

    void AppendMessage(string message);
    int GetMessageCount();

    vector<string> GetNextMessages(int count);
    string GetNextMessage();
};


#endif //TOTALTAGMQTTDOCKER_MESSAGECACHE_H

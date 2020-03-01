//
// Created by danim on 01/03/2020.
//

#ifndef TOTALTAGMQTTDOCKER_EVENTMANAGER_H
#define TOTALTAGMQTTDOCKER_EVENTMANAGER_H


#include <vector>

#include "TagInfo.h"
#include "TagInfoCache.h"

class EventManager
{
public:
    EventManager(TagInfoCache& messageCache);
    ~EventManager();

    void AddTagInfo(TagInfo& tagInfo);
    void AddTagInfo(vector<TagInfo>& tagInfos);

private:
    TagInfoCache& _messageCache;
};


#endif //TOTALTAGMQTTDOCKER_EVENTMANAGER_H

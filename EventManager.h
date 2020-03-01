//
// Created by danim on 01/03/2020.
//

#ifndef TOTALTAGMQTTDOCKER_EVENTMANAGER_H
#define TOTALTAGMQTTDOCKER_EVENTMANAGER_H


#include <vector>

#include "TagInfo.h"
#include "TotalTagSender.h"

class EventManager
{
public:
    EventManager(TotalTagSender& sender);
    ~EventManager();

    void AddTagInfo(TagInfo& tagInfo);
    void AddTagInfo(vector<TagInfo>& tagInfos);

private:
    TotalTagSender _sender;
};


#endif //TOTALTAGMQTTDOCKER_EVENTMANAGER_H

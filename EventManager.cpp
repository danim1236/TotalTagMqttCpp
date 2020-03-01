//
// Created by danim on 01/03/2020.
//

#include "EventManager.h"

EventManager::EventManager(TagInfoCache& messageCache)
:
_messageCache(messageCache)
{
}

EventManager::~EventManager()
{
}

void EventManager::AddTagInfo(vector<TagInfo> &tagInfos)
{
    for (int i = 0; i < tagInfos.size(); ++i) {
        AddTagInfo(tagInfos[i]);
    }
}

void EventManager::AddTagInfo(TagInfo &tagInfo)
{
    _messageCache.Append(tagInfo);
}



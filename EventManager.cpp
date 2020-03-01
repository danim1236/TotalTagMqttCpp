//
// Created by danim on 01/03/2020.
//

#include "EventManager.h"

#include <time.h>

EventManager::EventManager(TagInfoCache& messageCache)
:
_messageCache(messageCache),
_tagInfoMap(map<string, pair<int, time_t > >())
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
    auto forward = true;


    auto key = tagInfo.Epc;
//    auto key = make_pair(tagInfo.Epc, tagInfo.AntennaPort);

    if (_tagInfoMap.count(key) == 1) {
        auto ad = _tagInfoMap[key];
        bool sameAntenna = tagInfo.AntennaPort == ad.first;
        if (sameAntenna) {
            auto df = difftime(tagInfo.DateTime, ad.second);
            if (df < 2) {
                forward = false;
            }
        }
    }

    _tagInfoMap[key] = make_pair(tagInfo.AntennaPort, tagInfo.DateTime);

    if (forward) {
        _messageCache.Append(tagInfo);
    }
}



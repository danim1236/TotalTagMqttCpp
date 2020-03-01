//
// Created by danim on 01/03/2020.
//

#include "EventManager.h"

#include <time.h>

EventManager::EventManager(TagInfoCache& messageCache)
:
_messageCache(messageCache),
_tagInfoMap(map<string, vector<TagInfo> >()),
_antennaPortMap(map<string, int>())
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
    auto key = tagInfo.Epc;
    
    if (_tagInfoMap.count(key) == 0) {
        vector<TagInfo> v;
        v.reserve(100);
        _tagInfoMap[key] = v;
    } else {
        vector<TagInfo>& v(_tagInfoMap[key]);
        if (v.size() >= 100) {
            v.erase(v.begin());
        }
    }

    vector<TagInfo>& values(_tagInfoMap[key]);
    values.push_back(tagInfo);

    auto now = system_clock::now();
    auto oldest = now - std::chrono::milliseconds(500);

    double foundRssi = tagInfo.Rssi;
    int antennaPort = tagInfo.AntennaPort;

    for (auto v = values.end() - 1; v >= values.begin(); --v) {
        TagInfo &info(*v);
        if (info.DateTime < oldest) {
            break;
        }
        if (info.Rssi > foundRssi) {
            foundRssi = info.Rssi;
            antennaPort = info.AntennaPort;
        }
    }

    auto forward = _antennaPortMap.count(key) == 0 || _antennaPortMap[key] != antennaPort;

    if (forward) {
        _antennaPortMap[key] = antennaPort;
        _messageCache.Append(tagInfo);
    }
}



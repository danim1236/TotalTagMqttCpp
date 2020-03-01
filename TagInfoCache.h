//
// Created by danim on 01/03/2020.
//

#ifndef TOTALTAGMQTTDOCKER_TAGINFOCACHE_H
#define TOTALTAGMQTTDOCKER_TAGINFOCACHE_H


#include <vector>
#include <queue>
#include <mutex>
#include "TagInfo.h"

using namespace std;

class TagInfoCache
{
public:
    TagInfoCache();
    ~TagInfoCache();

    void Append(TagInfo message);
    int GetCount();

    vector<TagInfo> GetNexts();
    vector<TagInfo> GetNexts(int count);
    TagInfo GetNext();

private:
    queue<TagInfo> _cache;
    mutex _mutex;
};


#endif //TOTALTAGMQTTDOCKER_TAGINFOCACHE_H

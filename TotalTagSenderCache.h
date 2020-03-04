//
// Created by danim on 03/03/2020.
//

#ifndef TOTALTAGMQTTDOCKER_TOTALTAGSENDERCACHE_H
#define TOTALTAGMQTTDOCKER_TOTALTAGSENDERCACHE_H


#include <thread>
#include <memory.h>

#include "TagInfoCache.h"
#include "TotalTagSender.h"

using namespace std;

class TotalTagSenderCache
{
public:
    TotalTagSenderCache(TagInfoCache& tagInfoCache, TotalTagSender& totalTagSender);
    ~TotalTagSenderCache();

    bool Start();
    bool Stop();

private:
    TagInfoCache& _tagInfoCache;
    TotalTagSender& _totalTagSender;
    unique_ptr<thread> _thread;
    volatile bool _running;

    static void MainLoop(TotalTagSenderCache *instance);
};


#endif //TOTALTAGMQTTDOCKER_TOTALTAGSENDERCACHE_H

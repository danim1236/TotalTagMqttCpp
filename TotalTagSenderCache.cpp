//
// Created by danim on 03/03/2020.
//

#include "TotalTagSenderCache.h"

#include <iostream>
#include <time.h>

#include "Util.h"

TotalTagSenderCache::TotalTagSenderCache(TagInfoCache& tagInfoCache, TotalTagSender& totalTagSender)
:
_tagInfoCache(tagInfoCache),
_totalTagSender(totalTagSender),
_thread(nullptr),
_running(false)
{
}

TotalTagSenderCache::~TotalTagSenderCache()
{
    Stop();
}

bool TotalTagSenderCache::Start()
{
    auto ok = !_running;
    if (ok) {
        _running = true;
        _thread.reset(new thread(MainLoop, this));
    }

    return ok;
}

bool TotalTagSenderCache::Stop()
{
    auto ok = _running;
    if (ok) {
        _running = false;
        _thread->join();
    }

    return ok;
}

void TotalTagSenderCache::MainLoop(TotalTagSenderCache *instance)
{
    TagInfoCache& messageCache(instance->_tagInfoCache);
    TotalTagSender& sender(instance->_totalTagSender);

    while (instance->_running) {
        while (messageCache.GetCount() > 0) {
            TagInfo tagInfo = messageCache.PeekNext();
            cout << tagInfo.GetDateTime() << ' ' << tagInfo.Epc << ' ' << tagInfo.AntennaPort << tagInfo.Rssi << "... " << std::flush;

            bool tryAgain;
            do {
                try {
                    tryAgain = !sender.AddReadTag(tagInfo);
                }
                catch(...) {
                    tryAgain = true;
                }
                if (tryAgain) {
                    msleep(1000);
                }
            } while (tryAgain);

            messageCache.DiscardNext();

            cout <<  "Ok" << endl;
        }

        msleep(250);
    }
}

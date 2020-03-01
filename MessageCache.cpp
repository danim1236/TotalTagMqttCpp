//
// Created by danim on 01/03/2020.
//

#include "MessageCache.h"

MessageCache::MessageCache() {

}

MessageCache::~MessageCache() {

}

int MessageCache::GetMessageCount()
{
    unique_lock<std::mutex> mlock(_mutex);
    int size =_cache.size();
    mlock.unlock();

    return size;
}

string MessageCache::GetNextMessage()
{
    unique_lock<std::mutex> mlock(_mutex);
    string message(_cache.front());
    _cache.pop();
    mlock.unlock();

    return message;
}

void MessageCache::AppendMessage(string message)
{
    unique_lock<std::mutex> mlock(_mutex);
    _cache.push(string(message));
    mlock.unlock();
}

vector<string> MessageCache::GetNextMessages(int count)
{
    vector<string> ret(count);

    unique_lock<std::mutex> mlock(_mutex);

    for (int i = 0; i < count; ++i) {
        ret.push_back(_cache.front());
        _cache.pop();
    }
    mlock.unlock();

    return ret;
}

vector<string> MessageCache::GetNextMessages()
{
    return GetNextMessages(GetMessageCount());
}

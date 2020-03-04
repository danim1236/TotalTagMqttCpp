//
// Created by danim on 01/03/2020.
//

#include "TagInfoCache.h"

TagInfoCache::TagInfoCache()
{
}

TagInfoCache::~TagInfoCache()
{
}

int TagInfoCache::GetCount()
{
    unique_lock<std::mutex> mlock(_mutex);
    int size =_cache.size();
    mlock.unlock();

    return size;
}

TagInfo TagInfoCache::PeekNext()
{
    unique_lock<std::mutex> mlock(_mutex);
    TagInfo tagInfo(_cache.front());
    mlock.unlock();

    return tagInfo;
}

void TagInfoCache::DiscardNext()
{
    unique_lock<std::mutex> mlock(_mutex);
    _cache.pop();
    mlock.unlock();
}

TagInfo TagInfoCache::GetNext()
{
    unique_lock<std::mutex> mlock(_mutex);
    TagInfo tagInfo(_cache.front());
    _cache.pop();
    mlock.unlock();

    return tagInfo;
}

void TagInfoCache::Append(TagInfo tagInfo)
{
    unique_lock<std::mutex> mlock(_mutex);
    _cache.push(TagInfo(tagInfo));
    mlock.unlock();
}

vector<TagInfo> TagInfoCache::GetNexts(int count)
{
    vector<TagInfo> ret(count);

    unique_lock<std::mutex> mlock(_mutex);

    for (int i = 0; i < count; ++i) {
        ret.push_back(_cache.front());
        _cache.pop();
    }
    mlock.unlock();

    return ret;
}

vector<TagInfo> TagInfoCache::GetNexts()
{
    return GetNexts(GetCount());
}

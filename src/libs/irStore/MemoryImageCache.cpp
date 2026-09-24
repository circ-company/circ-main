#include "MemoryImageCache.h"



MemoryImageCache::MemoryImageCache(const Url aUrl, QObject *parent)
    : ImageCacheStore{aUrl, parent}
{}

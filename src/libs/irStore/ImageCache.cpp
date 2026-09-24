#include "ImageCache.h"

#include <Log.h>

#include "ImageCacheStore.h"

ImageCache::ImageCache(ImageCacheStore *parent)
    : QObject{parent}
{

}

ImageCacheStore *ImageCache::store() { CKPOINTER(mpStore); return mpStore; }

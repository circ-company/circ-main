#pragma once

#include <QObject>
#include "ImageCacheStore.h"

#include <Bytes.h>
#include <KeyMap.h>
#include <Uid.h>

class MemoryImageCache : public ImageCacheStore
{
    Q_OBJECT
public: // types


public: // ctors
    MemoryImageCache(const Url aUrl, QObject *parent = nullptr);


public slots:

signals:

public: // const

public: // non-const

public: // pointers

private:
    QMap<Uid, KeyMap> mIdMetaMap;
    QMap<Uid, Bytes> mIdBytesMap;
};

#pragma once

#include <QObject>

#include <Bytes.h>
#include <KeyMap.h>
#include <Id.h>

class ImageCacheStore;

class ImageCache : public QObject
{
    Q_OBJECT
public: // types
    enum Type
    {
        $null   = 0,
        Memory,
        File,
        Sql,
    };
    Q_ENUM(Type);

public: // ctors
    explicit ImageCache(ImageCacheStore *parent = nullptr);

public slots:

signals:

public: // const

public: // non-const
    bool open(const Url aStoreUrl);
    Id add(const KeyMap aKeyMap, const Bytes aBlob);


public: // pointers
    ImageCacheStore * store();

private:
    ImageCacheStore * mpStore=nullptr;
};



#pragma once

#include <QObject>
#include <Url.h>

class ImageCacheStore : public QObject
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
    ImageCacheStore(const Url aUrl, QObject *parent = nullptr);

public slots:

signals:

public: // const

public: // non-const

public: // pointers

};

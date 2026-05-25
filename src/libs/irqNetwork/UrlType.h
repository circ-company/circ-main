#pragma once

#include <Enumeration.h>

#define URLTYPE_ENUM(NV) \
    NV($null, = 0)  \
    NV(File,)  \
    NV(Files,)  \
    NV(TextFile,)  \
    NV(Dir,) \
    NV(WatchDir,) \
    NV(SQL,)  \
    NV(SQLite,)  \
    NV(PgSQL,)  \
    NV($other,)   \

class UrlType : public Enumeration
{
    DECLARE_ENUMERATION(UrlType, URLTYPE_ENUM)

public: // const
    bool isNull() const;
    bool isOther() const;
    bool isFile() const;
    bool isDir() const;
    bool isSql() const;
};


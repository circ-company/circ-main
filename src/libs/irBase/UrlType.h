#pragma once

#include <QObject>

#include "CText.h"
#include "Types.h"

class UrlType : public QObject
{
    Q_GADGET
public: // types
    enum Enum : BYTE
    {
        $null = 0,
        $File ,             //  1-Begin File
        File = $File,       //  1
        Files,              //  2
        TextFile,           //  3
        $Dir ,              //  4-Begin Dir
        Dir = $Dir,         //  4
        WatchDir,           //  5
        $SQL ,              //  6-Begin SQL
        SQL = $SQL,         //  6
        SQLite,             //  7
        PgSQL,              //  8
        $max
    };
    Q_ENUM(Enum);

public: // ctors
    UrlType(); // null
    UrlType(const BYTE val);
    UrlType(const CText nam);
    ~UrlType();

public: // const
    bool isNull() const;
    bool file() const;
    bool dir() const;
    bool sql() const;
    bool inRange(const Enum &lo, const Enum &hi) const;
    Enum evalue() const;
    BYTE value() const;
    CText name() const;

public: // non-const
    void nullify();
    bool set(const BYTE val);
    bool set(const CText nam);
    void set(const Enum other);

private:
    Enum mEnum=$null;

};

inline UrlType::Enum UrlType::evalue() const { return mEnum; }
inline BYTE UrlType::value() const { return BYTE(mEnum); }
inline void UrlType::nullify() { mEnum = $null; }
inline void UrlType::set(const Enum other) { mEnum = other; }


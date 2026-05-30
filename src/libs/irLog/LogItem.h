#pragma once

#include <QMetaType>

#include <CodeValue.h>
#include <CodeContext.h>
#include <KeyMap.h>
#include <Severity.h>
#include <Uid.h>

#include "LogMsgType.h"

class CodeContext;

class LogItem
{
public: // ctors
    LogItem(const bool &open); // or nil
    LogItem(const Severity sev, const CodeContext &ctx);

public: // const
    bool isNull() const;
    bool isNil() const;
    bool isEmpty() const;
    bool contains(const Key &key) const;
    AText at(const Key &key) const;
    Severity severity() const;
    AText message() const;
    AText contextString() const;
    LogMsgType logMessageType() const;

public: // non-const
    void clear();
    // setup
    void set(const Severity sev);
    void set(const CodeContext &ctx);
    // value
    void message(const AText &atx);
    void returnValue(const CodeValue &arg);
    void argument(const Index ix, const CodeValue &arg);
    // low level
    bool set(const Key &key, const AText &atx, const bool override=true);
    bool set(const Key &key, const int i, const bool override=true);
    void import(const KeyTextMap &other);


public: // pointers
    const Uid & uid() const;
    Uid & uid();
    const KeyTextMap & map() const;
    KeyTextMap & map();
    const LogItem & it() const;
    LogItem & it();

private:
    Uid mUid;
    KeyTextMap mMap;

public: // QMetaType
    LogItem() = default;
    ~LogItem() = default;
    LogItem(const LogItem &) = default;
    LogItem &operator=(const LogItem &) = default;
};

//Q_DECLARE_METATYPE(LogItem);

inline bool LogItem::isNull() const { return isNil() || isEmpty(); }
inline bool LogItem::isNil() const { return uid().isNil(); }
inline bool LogItem::isEmpty() const { return map().isEmpty(); }
inline bool LogItem::contains(const Key &key) const { return map().contains(key); }
inline AText LogItem::at(const Key &key) const { return map().value(key); }
inline AText LogItem::message() const { return at("/Message/Message"); }
inline AText LogItem::contextString() const { return at("/Base/ContextString"); }
inline const Uid &LogItem::uid() const { return mUid; }
inline Uid &LogItem::uid() { return mUid; }
inline const KeyTextMap &LogItem::map() const { return mMap; }
inline KeyTextMap &LogItem::map() { return *(KeyTextMap *)this; }
inline const LogItem &LogItem::it() const { return *this; }
inline LogItem &LogItem::it() { return *this; }

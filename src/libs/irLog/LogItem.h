#include <QMetaType>

#include <KeyMap.h>
#include <Severity.h>
#include <Uid.h>

#include "LogMsgType.h"

class LogItem
{
public: // ctors
    LogItem(const bool &open); // or nil
    LogItem(const KeyTextMap &other);

public: // const
    bool isNull() const;
    bool isNil() const;
    bool isEmpty() const;
    bool contains(const Key &key) const;
    AText at(const Key &key) const;
    Severity severity() const;
    LogMsgType logMessageType() const;

public: // non-const
    void clear();
    bool set(const Key &key, const AText &atx, const bool override=false);
    void import(const KeyTextMap &other);


public: // pointers
    const Uid & uid() const;
    const KeyTextMap & map() const;
    const LogItem & it() const;
    Uid & uid();
    KeyTextMap & map();
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

Q_DECLARE_METATYPE(LogItem);

inline bool LogItem::isNull() const { return isNil() || isEmpty(); }
inline bool LogItem::isNil() const { return uid().isNil(); }
inline bool LogItem::isEmpty() const { return map().isEmpty(); }
inline bool LogItem::contains(const Key &key) const { return map().contains(key); }
inline const Uid &LogItem::uid() const { return mUid; }
inline const KeyTextMap &LogItem::map() const { return mMap; }
inline const LogItem &LogItem::it() const { return *this; }
inline Uid &LogItem::uid() { return mUid; }
inline KeyTextMap &LogItem::map() { return *(KeyTextMap *)this; }
inline LogItem &LogItem::it() { return *this; }

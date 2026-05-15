#include "LogItem.h"


LogItem::LogItem(const bool &open)
    : mUid(open ? Uid::VerGTimeseqNode6 : Uid(true)) {;}
LogItem::LogItem(const KeyTextMap &other)
    : mUid(Uid::VerGTimeseqNode6), mMap(other) {;}

Severity LogItem::severity() const
{
    Severity result;
    if (contains("Severity"))
    {
        AText tSevText = at("Severity");
        Severity tSev(tSevText);
        if (tSev.isValid())
            result = tSev;
    }
    return result;
}

LogMsgType LogItem::logMessageType() const
{
    LogMsgType result;
    if (contains("MessageType"))
    {
        LogMsgType::Type tLMTT = LogMsgType::from("MessageType");
        if (tLMTT > LogMsgType::$null)
            result.set(tLMTT);
    }
    else if (contains("Severity"))
    {
        Severity tSev = severity();
        LogMsgType::Type tLMTT = LogMsgType::from(tSev);
        if (tLMTT > LogMsgType::$null)
            result.set(tLMTT);
    }
    return result;
}

void LogItem::clear()
{
    map().clear();
}

bool LogItem::set(const Key &key, const AText &atx, const bool override)
{
    return map().set(key, atx, override);
}

void LogItem::import(const KeyTextMap &other)
{
    mMap.insert(other);
}


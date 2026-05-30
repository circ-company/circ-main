#include "LogItem.h"

#include <CodeContext.h>

LogItem::LogItem(const bool &open)
    : mUid(open ? Uid::VerGTimeseqNode6 : Uid(true)) {;}
LogItem::LogItem(const Severity sev, const CodeContext &ctx)
    { set(ctx), set(sev); }

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

void LogItem::set(const Severity sev)
{
    set("Base/Severity", sev.name(), true);
}

void LogItem::set(const CodeContext &ctx)
{
    set("Base/ContextString", ctx.toDebugString(), true);
    set("Context/TimeStampEns", ctx.epochNS());
    set("Context/qfiText", ctx.qfiText());
    set("Context/fileName", ctx.fileName());
    set("Context/fileLine", ctx.fileLine());
    set("Context/funcInfo", ctx.funcInfo().toDebugString()); // TODO multiple lines
    set("Context/fileInfo", ctx.fileInfo().toString());
}

void LogItem::message(const AText &atx)
{
    if (contains("Message/Message"))
        set("Message/Message", atx);
    else
        set("Base/Message", atx, false);
}

void LogItem::returnValue(const CodeValue &arg)
{
    Key tBaseKey("/Return/");
    set(tBaseKey + "Value", arg.string(), true);
    set(tBaseKey + "Name", arg.name(), true);
    set(tBaseKey + "MetaName", arg.metaName(), true);
    set(tBaseKey + "MetaType", arg.metaType().id(), true);
}

void LogItem::argument(const Index ix, const CodeValue &arg)
{
    Key tBaseKey("/Argument/" + QString::number(ix));
    set(tBaseKey + "Value", arg.string(), true);
    set(tBaseKey + "Name", arg.name(), true);
    set(tBaseKey + "MetaName", arg.metaName(), true);
    set(tBaseKey + "MetaType", arg.metaType().id(), true);
}

bool LogItem::set(const Key &key, const AText &atx, const bool override)
{
    return map().set(key, atx, override);
}

bool LogItem::set(const Key &key, const int i, const bool override)
{
    return set(key, QString::number(i), override);
}

void LogItem::import(const KeyTextMap &other)
{
    mMap.insert(other);
}


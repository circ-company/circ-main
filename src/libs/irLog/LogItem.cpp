#include "LogItem.h"

#include <CodeContext.h>

LogItem::LogItem(const Type type, const StatusLevel &lvl, const CodeContext &ctx)
    : mUid(Uid::VerGTimeseqNode6)
{
    mType = type;
    mLevel = lvl;
    mContext = ctx;
}

AText LogItem::formatted() const
{
    AText result;
    switch (type())
    {
    default:
    case Log::MessageOnly:      result = message();                     break;
    case Log::Formatted:        result = formatValues();                break;
    }
    return result;
}

void LogItem::clear()
{
    mUid.nilify();
    mType = Type::$nullType;
    mLevel.nullify();
    mContext.clear();
    mMessage.clear();
    mValues.clear();
}

void LogItem::set(const Index ix, const CodeValue &cv)
{
    codeValues().set(ix, cv);
}

void LogItem::asert(const Log::Operator op, const bool is, const char * exp)
{
    set(op);
    set(CodeValue(is, exp));
}

AText LogItem::formatValues() const
{
    return AText::formatted(message(), codeValues().values());
}


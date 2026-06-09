#include "LogItem.h"

#include <CodeContext.h>

LogItem::LogItem(const Type type, const CText &slvName, const CodeContext &ctx)
    : mUid(Uid::VerGTimeseqNode6)
    , mType(type)
    , mLevel(slvName)
    , mContext(ctx) {;}

LogItem::LogItem(const Type type, const StatusLevel &slv, const CodeContext &ctx)
    : mUid(Uid::VerGTimeseqNode6)
    , mType(type)
    , mLevel(slv)
    , mContext(ctx) {;}

AText LogItem::formatted() const
{
    ATextList tDbgAtxl;
    AText result = value(0).string();
    for (Index ix = 1; ix < Index(count()); ++ix)
    {
        AText tPctNum = QString("%") + QString::number(ix, 10);
        if (result.contains(tPctNum))
            result.replace(tPctNum.toQBAV(), AText(value(ix).string()));
        tDbgAtxl << value(ix).toDebugString();
    }
    return result + AText("\n") + tDbgAtxl.join("\n");
}

void LogItem::clear()
{
    mUid.nilify();
    mType = Type::$null;
    mLevel.nullify();
    mContext.clear();
    mMessage.clear();
    mValues.clear();
}

void LogItem::set(const Index ix, const CodeValue &cv)
{
    codeValues().set(ix, cv);
}

void LogItem::asert(const LogOperator::Enum op, const bool is, const char * exp)
{
    set(op);
    set(CodeValue(is, exp));
}


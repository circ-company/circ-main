#include "LogItem.h"

#include <CodeContext.h>

LogItem::LogItem(const Type type, const CText &sevName, const CodeContext &ctx)
    : mUid(Uid::VerGTimeseqNode6)
    , mType(type)
    , mSeverity(Severity(sevName))
    , mContext(ctx) {;}

LogItem::LogItem(const Type type, const Severity::Enum &sen, const CodeContext &ctx)
    : mUid(Uid::VerGTimeseqNode6)
    , mType(type)
    , mSeverity(sen)
    , mContext(ctx) {;}

LogItem::LogItem(const Type type, const Severity &sev, const CodeContext &ctx)
    : mUid(Uid::VerGTimeseqNode6)
    , mType(type)
    , mSeverity(Severity(sev))
    , mContext(ctx) {;}

AText LogItem::formatted() const
{
    ATextList tDebug;
    AText result = value(0).string();
    for (Index ix = 1; ix < Index(count()); ++ix)
    {
        AText tPctNum = QString("%%%1").arg(ix);
        if (result.contains(tPctNum))
            result.replace(tPctNum.toQBAV(), AText(value(ix).string()));
        tDebug << value(ix).toDebugString();
    }
    return result + AText("\n") + tDebug.join("\n");
}

void LogItem::clear()
{
    mUid.nilify();
    mType = Type::$null;
    mSeverity.nullify();
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
    set(CodeValue(CodeValue::Variable, is, exp));
}

void LogItem::set(const Severity::Enum sev)
{
    mSeverity = Severity(BYTE(sev));
}



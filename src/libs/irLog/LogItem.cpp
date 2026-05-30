#include "LogItem.h"

#include <CodeContext.h>

LogItem::LogItem(const Type type, const Severity sev, const CodeContext &ctx)
    : mUid(Uid::VerGTimeseqNode6)
    , mType(type)
    , mSeverity(sev)
    , mContext(ctx) {;}

AText LogItem::formatted() const
{
    AText result = message();
    // case Message:
    return result;
}

void LogItem::clear()
{
    mUid.nilify();
    mType = Type::$null;
    mSeverity = Severity::$null;
    mContext.clear();
    mMessage.clear();
    mValues.clear();
}

void LogItem::set(const Index ix, const CodeValue &cv)
{
    codeValues().set(ix, cv);
}

void LogItem::asert(const LogOperator op, const bool is, const char * exp)
{
    set(op);
    set(CodeValue(CodeValue::Variable, is, exp));
}

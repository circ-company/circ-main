#include "LogItem.h"

#include <CodeContext.h>

LogItem::LogItem(const Type type, const Severity sev, const CodeContext &ctx)
    : mUid(Uid::VerGTimeseqNode6)
    , mType(type)
    , mSevValue(sev)
    , mContext(ctx) {;}

AText LogItem::formatted() const
{
    ATextList tDebug;
    AText result = value(0).string();
    for (Index ix = 1; ix < count(); ++ix)
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
    mSevValue = Severity::$null;
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

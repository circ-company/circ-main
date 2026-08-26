#include "LogItem.h"

#include <CodeContext.h>
#include <Log.h>
#include <TypeFormat.h>

LogItem::LogItem(const Type type, const StatusLevel &lvl, const CodeContext &ctx)
    : mUid(Uid::VerGTimeseqNode6)
    , mEMS(MillisecondTime::current())
    , mType(type)
    , mLevel(lvl)
    , mContext(ctx)
    , mOperator(Log::$nullOperator) {;}

QVariant LogItem::var(const Index ix) const
{
    return (ix >= 0 && Count(ix) < varCount())
                ? mVarList.value(ix)
                : QVariant();
}

AText LogItem::formatted() const
{
    AText result;
    result = mFormat.formatted(vars());
    return result;
}

void LogItem::clear()
{
    mUid.nilify();
    mType = Type::$nullType;
    mLevel.nullify();
    mContext.clear();
    mFormat.clear();
    mOperator = Log::$nullOperator;
    mVarList.clear();
}

void LogItem::text(const AText aVar)
{
    mVarList.append(aVar());
}

void LogItem::pointer(void *aPtr, const char *aExpression)
{
    if (Log::evaluate(Log::NotEqual, 0, qptrdiff(aPtr)))
        level(StatusLevel::TOK);
#if 1 // def __LOG_SUPRESS_OK
    if (level().notWarn()) return;                                /*/=====\*/
#endif
    format("Pointer %1 %2 at 0x%3");
    set(aExpression);
    set(level().notWarn() ? "OK" : "FAIL");
    set(QString::number(qptrdiff(aPtr), 16));
}

void LogItem::assertIs(const Log::Operator aOp, const bool aIs,
                       const char *aExpression)
{
    if (Log::evaluate(aOp, aIs)) level(StatusLevel::TOK);
    format(AText("Assertion %1 %2: %3"));
    set(QVariant(level().notWarn() ? "OK" : "FAIL"));
    set(QVariant(Log::True == aOp ? "true" : "false"));
    set(QVariant(aExpression));
}

void LogItem::expect(const Log::Operator aOp,
                     const QVariant aActVar, const char *aActText)
{
    format(AText("Expected %1 is %2 for %3"));
    set(AText(aActText));
    set(aActVar);
    set(QVariant(int(aOp)));
    op(aOp);
    if (Log::evaluate(aOp, aActVar))
        mLevel = StatusLevel::TOK;
}

void LogItem::expect(const Log::Operator aOp,
                     const QVariant aExpVar, const char *aExpText,
                     const QVariant aActVar, const char *aActText)
{
    format(AText("Expected %1 is %2 to %3 Actual %4 is %5"));
    set(AText(aActText));
    set(aActVar);
    set(QVariant(int(aOp)));
    set(AText(aExpText));
    set(aExpVar);
    op(aOp);
    if (Log::evaluate(aOp, aExpVar, aActVar))
        mLevel = StatusLevel::TOK;
}

bool LogItem::connect(QObject *sender, const QMetaMethod &signal,
                      QObject *receiver, const QMetaMethod &method,
                      const char *pchSender,
                      const char *pchSignal, const char *pchReceiver,
                      const char *pchMethod)
{
    TriBool result;
    QObject * pSender = qobject_cast<QObject*>(sender);
    QObject * pReceiver = qobject_cast<QObject*>(receiver);
    result.expect(nullptr != pSender);
    result.expect(nullptr != pReceiver);
    CKPOINTER(pSender);
    CKPOINTER(pReceiver);
    if (result.isInvalid()) // nothing failed yet
    {
        const bool cOK = QObject::connect(pSender, signal,
                                          pReceiver, method);
        result.expect(cOK);
    }
    if (result.isInvalid()) level(StatusLevel::TOK);
    format(AText("Connect %1 for %2,%3 to %4,%5"));
    set(QVariant(AText(level().isError() ? "FAIL" : "OK")));
    set(QVariant(AText(pchSender)));
    set(QVariant(AText(pchSignal)));
    set(QVariant(AText(pchReceiver)));
    set(QVariant(AText(pchMethod)));
    if ( ! isFault()) result.truify();
    WASSERT(result);
    return result;
}

void LogItem::newobj(QObject *pNewObj, const CText &aObjName, QObject *pParent)
{
    QMetaType tQmtObject = QMetaType::fromName(aObjName);
    const QMetaType cQmtParent = pParent->metaObject()->metaType();
    if (nullptr == pNewObj)
    {
        level(StatusLevel::MAlloc);
        format(AText("FAIL: Memory Allocation for <%1 %2(%3)> parent<%4(%5)>"));
    }
    else
    {
        level(StatusLevel::Info);
        tQmtObject = pNewObj->metaObject()->metaType();
        format(AText("OK: Memory Allocation for <%1 %2(%3) at &6> parent<%4(%5)>"));
    }
    set(aObjName);
    set(AText(tQmtObject.name()));
    set(QVariant(int(tQmtObject.id())));
    set(AText(cQmtParent.name()));
    set(QVariant(int(cQmtParent.id())));
    if (pNewObj) set(AText::formatHeximal((qptrdiff)pNewObj));
}

void LogItem::dumpVar(const QVariant aVar, const char * aText)
{
    const QMetaType cQMT = aVar.metaType();
    const AText cFmt = QString("Dump %1(%2): `%3` is <%4>");
    format(cFmt);
    set(AText(cQMT.name()));
    set(QVariant(int(cQMT.id())));
    set(AText(aText));
    set(aVar);
}

void LogItem::dumpAll(const QVariant aVar, const char *aText)
{
    const QMetaType cQMT = aVar.metaType();
    const AText cFmt = QString("Dump %1(%2): `%3");
    format(cFmt);
    set(AText(cQMT.name()));
    set(QVariant(int(cQMT.id())));
    set(AText(aText));
    set(aVar);
}


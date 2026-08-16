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
    , mOperator(Log::$nullOperator)
{
}

QVariant LogItem::var(const Index ix) const
{
    return (ix >= 0 && Count(ix) < varCount())
                ? mVarList.value(ix)
                : QVariant();
}

AText LogItem::formatted() const
{
//    qDebug() << Q_FUNC_INFO << mFormat;
    AText result;
    if (varCount() && ! isList())
        result = mFormat.formatted(vars());
    else
        result = mFormat;
    return result;
}

bool LogItem::isList() const
{
    return (1 == varCount())
               ? QMetaType::fromName("ATextList") == var(0).metaType()
               : false;
}

void LogItem::clear()
{
    mUid.nilify();
    mType = Type::$nullType;
    mLevel.nullify();
    mContext.clear();
    mFormat.clear();
    mVarList.clear();
}

void LogItem::set(const AText &aText)
{
    if (mFormat.isEmpty())
        mFormat = aText;
    else
        set(QVariant(aText));
}

void LogItem::assertIs(const Log::Operator aOp, const bool aIs,
                       const char *aExpression)
{
    if (Log::evaluate(aOp, aIs)) level(StatusLevel::TOK);
    set(AText("Assertion %1 %2: %3"));
    set(QVariant(level().notWarn() ? "OK" : "FAIL"));
    set(QVariant(Log::True == aOp ? "true" : "false"));
    set(QVariant(aExpression));
}

void LogItem::expect(const Log::Operator aOp,
                     const QVariant aActVar, const char *aActText)
{
    set(AText("Expected %1 is %2 for %3"));
    set(AText(aActText));
    set(aActVar);
    set(QVariant(int(aOp)));
    set(aOp);
    if (Log::evaluate(aOp, aActVar))
        mLevel = StatusLevel::TOK;
}

void LogItem::expect(const Log::Operator aOp,
                     const QVariant aExpVar, const char *aExpText,
                     const QVariant aActVar, const char *aActText)
{
    set(AText("Expected %1 is %2 to %3 Actual %4 is %5"));
    set(AText(aActText));
    set(aActVar);
    set(QVariant(int(aOp)));
    set(AText(aExpText));
    set(aExpVar);
    set(aOp);
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
    WEXPECTNE(0, qptrdiff(pSender));
    WEXPECTNE(0, qptrdiff(pReceiver));
    if (result.isInvalid()) // nothing failed yet
    {
        const bool cOK = QObject::connect(pSender, signal,
                                          pReceiver, method);
        result.expect(cOK);
    }
    if (result.isInvalid()) level(StatusLevel::TOK);
    set(AText("Connect %1 for %2,%3 to %4,%5"));
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
        set(AText("FAIL: Memory Allocation for <%1 %2(%3)> parent<%4(%5)>"));
    }
    else
    {
        level(StatusLevel::Info);
        tQmtObject = pNewObj->metaObject()->metaType();
        set(AText("OK: Memory Allocation for <%1 %2(%3) at &6> parent<%4(%5)>"));
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
    set(cFmt);
    set(AText(cQMT.name()));
    set(QVariant(int(cQMT.id())));
    set(AText(aText));
    set(aVar);
}

void LogItem::dumpAll(const QVariant aVar, const char *aText)
{
    const QMetaType cQMT = aVar.metaType();
    const AText cFmt = QString("Dump %1(%2): `%3");
    set(cFmt);
    set(AText(cQMT.name()));
    set(QVariant(int(cQMT.id())));
    set(AText(aText));
    set(aVar);
}


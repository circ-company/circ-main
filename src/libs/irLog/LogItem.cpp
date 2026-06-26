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

void LogItem::set(const Index ix, const ArgumentInfo &cv)
{
    arguments().set(ix, cv);
}

void LogItem::assertIs(const Log::Operator aOp, const bool aIs, const char *aExpression)
{
    Q_ASSERT(!"TODO"); // TODO LogItem::assertIs()
    Q_UNUSED(aOp); Q_UNUSED(aIs); Q_UNUSED(aExpression);
}

void LogItem::expect(const Log::Operator aOp,
                     const QVariant aActVar, const char *aActText)
{
    set(AText::formatted("Expected %1; Actual %2 is %3",
                         QVariantList() << Log::opName(aOp)
                                        << aActText << aActVar));
}

void LogItem::expect(const Log::Operator aOp,
                     const QVariant aExpVar, const char *aExpText,
                     const QVariant aActVar, const char *aActText)
{
    set(AText::formatted("Expected %1 is %2 to %3 Actual %4 is %5",
                         QVariantList() << aActText << aActVar
                                        << Log::opName(aOp)
                                        << aExpText << aExpVar));
}

void LogItem::newobj(QObject *pObj, const CText &aObj, const AText &aArg,
                     QObject *pPar, const CText &aPar)
{
    Q_ASSERT(Log::Malloc == type()); Q_UNUSED(aArg); Q_UNUSED(pPar);
    if (nullptr == pObj)
    {
        level(StatusLevel::MAlloc);
        set("Memory Allocation Failure for <%1 %2(%3)> parent<%4(%5)>");
        set(1, ArgumentInfo(aObj, QMetaType::fromName(aObj)));
        set(2, ArgumentInfo(QMetaType::fromName(aObj).name()));
        set(3, ArgumentInfo("QMetaType::id()", QVariant(QMetaType::fromName(aObj).id())));
        set(4, ArgumentInfo(QMetaType::fromName(aPar).name()));
        set(5, ArgumentInfo("QMetaType::id()", QVariant(QMetaType::fromName(aPar).id())));
    }
    else
    {
        level(StatusLevel::Info);
        set("Memory Allocation for <%1 %2(%3)> parent<%4(%5)>");
        set(1, ArgumentInfo(aObj, QMetaType::fromName(aObj)));
        set(2, ArgumentInfo(pObj->metaObject()->metaType().name()));
        set(3, ArgumentInfo("QMetaType::id()", QVariant(pObj->metaObject()->metaType().id())));
        set(4, ArgumentInfo(QMetaType::fromName(aPar).name()));
        set(5, ArgumentInfo("QMetaType::id()", QVariant(QMetaType::fromName(aPar).id())));

    }
}

AText LogItem::formatValues() const
{
    return AText::formatted(AText(argument(0).value().toString()),
                            arguments().values());
}


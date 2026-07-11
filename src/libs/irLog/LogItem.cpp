#include "LogItem.h"

#include <CodeContext.h>
#include <TypeFormat.h>

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
    case Type::Malloc:          Q_FALLTHROUGH();
    case Type::Assert:          Q_FALLTHROUGH();
    case Type::Expect:          Q_FALLTHROUGH();
    case Log::Formatted:        result = formatValues();                break;
    default:                    Q_FALLTHROUGH();
    case Log::MessageOnly:      result = message();                     break;
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
    mArgInfoList.clear();
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
    set(1, ArgumentInfo("Text", aActText));
    set(2, ArgumentInfo("Value", aActVar));
    set(AText::format("Expected %1; Actual %1 is %2",
                         aActText, aActVar));
    // TODO fix wierdness
}

void LogItem::expect(const Log::Operator aOp,
                     const QVariant aExpVar, const char *aExpText,
                     const QVariant aActVar, const char *aActText)
{
    set(AText::format("Expected %1 is %2 to %3 Actual %4 is %5",
                         QVariantList() << aActText << aActVar
                                        << Log::opName(aOp)
                                        << aExpText << aExpVar));
}

void LogItem::newobj(QObject *pNewObj, const CText &aObjName, const AText &aObjType,
                     QObject *pParent, const CText &aParentType)
{
    Q_ASSERT(Log::Malloc == type()); //Q_UNUSED(aPar); Q_UNUSED(pPar);
    QMetaType tQmtObject = QMetaType::fromName(aObjName);
    const QMetaType cQmtParent = pParent->metaObject()->metaType();

    if (nullptr == pNewObj)
    {
        if (level().isNull()) level(StatusLevel::MAlloc);
        set("FAIL: Memory Allocation for <%1 %2(%3)> parent<%4(%5)>");
        set(6, ArgumentInfo(aObjName, (qptrdiff)(nullptr)));
    }
    else
    {
        level(StatusLevel::Info);
        tQmtObject = pNewObj->metaObject()->metaType();
        set("OK: Memory Allocation for <%1 %2(%3) at &6> parent<%4(%5)>");
        set(6, ArgumentInfo("NewObj Ptr", (qptrdiff)(pNewObj)));
    }
    set(1, ArgumentInfo("NewObj Name", aObjName));
    set(2, ArgumentInfo("Object MetaName", tQmtObject.name()));
    set(3, ArgumentInfo("Object MetaId()", tQmtObject.id()));
    set(4, ArgumentInfo("Parent MetaName", cQmtParent.name()));
    set(5, ArgumentInfo("Parent MetaId()", cQmtParent.id()));
}

void LogItem::dumpVar()
{
    QString tFmtStr = message();
    ArgumentInfo tAI = argument();
    CText tName = tAI.name();
    QVariant tVar = tAI.value();
    QMetaType tQMT = tAI.metaType();
    AText tMsg = QString(tFmtStr).arg(tQMT.name()).arg(tQMT.id())
                     .arg(tName()).arg(TypeFormat(tVar)());
    set(tMsg);
}

AText LogItem::formatValues() const
{
    AText tArgFmt = AText(argument(0).value().toString());
    if (tArgFmt.isEmpty()) tArgFmt = message();
    return AText::format(tArgFmt, arguments().values());
}


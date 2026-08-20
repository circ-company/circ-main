#include "StatusLevel.h"

#include "Utility.h"

NamedInt StatusLevel::smNamedInt;

StatusLevel::StatusLevel(const int val) { set(val); }
StatusLevel::StatusLevel(const CText &nam)  { set(nam); }

QChar StatusLevel::prefix() const
{
    QChar result(0x2753);
         if (false)         ;
    else if (info())        result = QChar(u'-'); //QChar(0x00B0);
    else if (trace())       result = QChar(u'+'); //QChar(0x2705);
    else if (warn())        result = QChar(u'!'); //QChar(0x270B);
    else if (error())       result = QChar(u'#'); //QChar(0x26D4);
    else if (fault())       result = QChar(u'&'); //QChar(0x267F);
    else                    result = QChar(u'?'); //QChar(0x2B55);
    return result;
}

QString StatusLevel::string(const int aWidth) const
{
    return QString("%1").arg(name()(), aWidth, prefix());
}

bool StatusLevel::inRange(const Value &lo, const Value &hi) const
{
    Q_ASSERT(lo < hi);
    return Utility::inRange((int)lo, value(), (int)hi);
}

void StatusLevel::nullify()
{
    instance()->set($null);
}

void StatusLevel::set(const int val)
{
    if (smNamedInt.contains(val))
        mValue = Value(val);
    else
        nullify();
}

bool StatusLevel::isValid(const StatusLevel aLevel)
{
    return aLevel < Invalid;
}

void StatusLevel::set(const CText &nam)
{
    nullify();
    if (smNamedInt.contains(nam))
        set(smNamedInt.value(nam));
}

bool operator == (const StatusLevel &lhs, const StatusLevel &rhs)
{
    return lhs.equal(rhs);
}

bool operator < (const StatusLevel &lhs, const StatusLevel &rhs)
{
    return lhs.less(rhs);
}

bool operator <= (const StatusLevel &lhs, const StatusLevel &rhs)
{
    return lhs.less(rhs) || lhs.equal(rhs);
}

// ======================== static =========================

StatusLevel *StatusLevel::instance()
{
    static StatusLevel * smpInstance = nullptr;
    if (nullptr == smpInstance)
    {
        smpInstance = new StatusLevel;
        load(initializer());
    }
    return smpInstance;
}

void StatusLevel::load(const PairList &pairs)
{
    smNamedInt.clear();
    foreach (const Pair cPair, pairs)
        smNamedInt.insert(cPair.first, cPair.second);
}

StatusLevel::PairList StatusLevel::initializer()
{
    return PairList()
           << Pair($null, "$null")
           << Pair(FuncArg, "FuncArg")
           << Pair(FuncReturn, "FuncReturn")
           << Pair(FuncEmit, "FuncEmit")
           << Pair(FuncRes, "FuncRes")
           << Pair(FuncResEn, "FuncResEn")
           << Pair(FuncEnter, "FuncEnter")
           << Pair(DumpHex, "DumpHex")
           << Pair(DumpVar, "DumpVar")
           << Pair(DumpObj, "DumpObj")
           << Pair(TDetail, "TDetail")
           << Pair(TOK, "TOK")
           << Pair(TraceMsg, "TraceMsg")
           << Pair(TProgress, "TProgress")
           << Pair(TPrefer, "TPrefer")
           << Pair(TExpect, "TExpect")
           << Pair(TAssert, "TAssert")
           << Pair(Exit, "Exit")
           << Pair(Detail, "Detail")
           << Pair(Info, "Info")
           << Pair(Prefer, "Prefer")
           << Pair(Progress, "Progress")
           << Pair(Start, "Start")
           << Pair(Warning, "Warning")
           << Pair(WPrefer, "WPrefer")
           << Pair(WExpect, "WExpect")
           << Pair(WAssert, "WAssert")
           << Pair(WMalloc, "WMalloc")
           << Pair(Error, "Error")
           << Pair(Expect, "Expect")
           << Pair(Assert, "Assert")
           << Pair(Thread, "Thread")
           << Pair(MustDo, "MustDo")
           << Pair(Process, "Process")
           << Pair(MAlloc, "MAlloc")
           << Pair(Invalid, "Invalid");
}

bool StatusLevel::isWarn() const
{
    return inRange($Warn, $max);
}

bool StatusLevel::isError() const

{
#if defined(__CIRC__WARN_IS_ERROR)
    return inRange($Warn, $max);
#endif
    return inRange($Error, $max);
}

bool StatusLevel::isFault() const
{
#if defined(__CIRC__WARN_IS_FAULT)
    return inRange($Warn, $max);
#elif defined(__CIRC__ERROR_IS_FAULT)
    return inRange($Error, $max);
#endif
    return inRange($Fault, $max);
}

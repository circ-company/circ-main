#include "StatusLevel.h"

#include "Utility.h"

NamedInt StatusLevel::smNamedInt;

StatusLevel::StatusLevel(const int val) { set(val); }
StatusLevel::StatusLevel(const CText &nam)  { set(nam); }

bool StatusLevel::inRange(const StatusLevel &lo, const StatusLevel &hi) const
{
    return Utility::inRange(lo, it(), hi);
}

void StatusLevel::set(const int val)
{
    nullify();
    if (smNamedInt.contains(val))
        mValue = Value(val);
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

// ======================== status =========================

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
           << Pair(FuncLeave, "FuncLeave")
           << Pair(FuncEnter, "FuncEnter")
           << Pair(DumpHex, "DumpHex")
           << Pair(DumpVar, "DumpVar")
           << Pair(DumpObj, "DumpObj")
           << Pair(TDetail, "TDetail")
           << Pair(TraceMsg, "TraceMsg")
           << Pair(TProgress, "TProgress")
           << Pair(TPrefer, "TPrefer")
           << Pair(TExpect, "TExpect")
           << Pair(TAssert, "TAssert")
           << Pair(Detail, "Detail")
           << Pair(Info, "Info")
           << Pair(Prefer, "Prefer")
           << Pair(Progress, "Progress")
           << Pair(Exit, "Exit")
           << Pair(Start, "Start")
           << Pair(Warning, "Warning")
           << Pair(WPrefer, "WPrefer")
           << Pair(WExpect, "WExpect")
           << Pair(WAssert, "WAssert")
           << Pair(WMemory, "WMemory")
           << Pair(Error, "Error")
           << Pair(Expect, "Expect")
           << Pair(Assert, "Assert")
           << Pair(Thread, "Thread")
           << Pair(Process, "Process")
           << Pair(MAlloc, "MAlloc")
           << Pair(System, "System")
           << Pair($max, "$max");
}


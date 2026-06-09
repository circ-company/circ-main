#include "Result.h"

Result::Result(const CodeContext &ctx) : mEpochNS(NanosecondTime::current()), mContext(ctx) {;}

bool Result::isValidStatusIndex(const Index ix) const
{
    return ix >=0 && ix < Index(statusCount());
}

StatusCode Result::status(const Index ix) const
{
    return isValidStatusIndex(ix) ? mStatusCodeList.at(ix) : StatusCode();
}

void Result::clear()
{
    mMinLevel.invalidate();
    mMaxLevel.invalidate();
    mStatusCodeList.clear();
    mLevelStatusMMap.clear();
}

void Result::add(const StatusCode &sts)
{
    mMaxLevel.max(sts.level().value());
    mMinLevel.min(sts.level().value());
    mStatusCodeList.append(sts);
    mLevelStatusMMap.insert(sts.level(), sts);
}

void Result::add(const StatusCode::List &stsl)
{
    foreach (const StatusCode cSts, stsl) add(cSts);
}


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
    mSeverity = Severity::$null;
    mStatusCodeList.clear();
    mSevStatusMMap.clear();
}

void Result::add(const StatusCode &sts)
{
    mSeverity.max(sts.severity());
    mStatusCodeList.append(sts);
    mSevStatusMMap.insert(sts.severity(), sts);
}

void Result::add(const StatusCode::List &stsl)
{
    foreach (const StatusCode cSts, stsl) add(cSts);
}


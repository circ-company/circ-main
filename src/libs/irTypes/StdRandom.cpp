#include "StdRandom.h"

StdRandom::StdRandom() { set(Range(0, 0)); }
StdRandom::StdRandom(const Range aRange) { set(aRange); }
StdRandom::StdRandom(const int aMax, const int aMin) { set(Range(aMin, aMax)); }

bool StdRandom::isNull() const
{
    return ! (mRange.first <= mRange.second);
}

bool StdRandom::isStdNull() const
{
    return (mDistribution.a() >= mDistribution.b());
}

void StdRandom::clear()
{
    mRange = Range(0, 0);
    mDistribution = std::uniform_int_distribution<int>(+1, -1);
}

void StdRandom::set(const Range aRange)
{
    clear();
    mRange = aRange;
}

int StdRandom::take()
{
    int result = 0;
    if (isNull())  return result;
    if (isStdNull())
    {
        mGenerator = std::mt19937(mDevice());
        mDistribution = std::uniform_int_distribution<int>(mRange.first,
                                                           mRange.second);
    }
    result = mDistribution(mGenerator);
    return result;
}


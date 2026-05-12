#include "NanosecondTime.h"

#include <chrono>

NanosecondTime::NanosecondTime(const Nanoseconds kTicks) { set(kTicks); }

bool NanosecondTime::isNull() const
{
    return -1 == mNanoTicks;
}

bool NanosecondTime::isValid() const
{
    return nanoYear(1580) <= mNanoTicks && mNanoTicks <= nanoYear(3000);
}

time_t NanosecondTime::timeT() const
{
    std::time_t result;
    std::chrono::time_point<std::chrono::system_clock,
                            std::chrono::duration<Nanoseconds> >
        tTPns( (std::chrono::duration<Nanoseconds>(mNanoTicks)) );
    result = std::chrono::system_clock::to_time_t(tTPns);
    return result;
}

SQWORD NanosecondTime::hecto() const
{
    return mNanoTicks / 100LL;
}

QDateTime NanosecondTime::toDateTime() const
{
    std::time_t tSTT = epochSTT(mNanoTicks);
    QDateTime result = QDateTime::fromMSecsSinceEpoch(tSTT / (NanosecondTime::nanoFactor() / 1000LL));
    return result;
}

QString NanosecondTime::toString(const QString &format) const
{
    return toDateTime().toString(format.isEmpty()
                                     ? "yyyy/MM/dd hh:mm:ss.zzz"
                                     : format) + nanoString();
}

QString NanosecondTime::nanoString() const
{
    const Nanoseconds cNanos  = value() % 1000LL;
    const Nanoseconds cMicros = (value() / 1000LL) % 1000LL;
    return QString(" %1 %2").arg(cMicros, 3, u'0').arg(cNanos, 3, u'0');
}

QString NanosecondTime::timeString() const
{
    return toDateTime().toString("hh:mm:ss.zzz") + nanoString();
}

void NanosecondTime::set(const Nanoseconds kTicks) // 0=use current
{
    if (0 == kTicks)
    {
        mNanoTicks = current();
    }
    else
    {
        std::chrono::nanoseconds tKT(kTicks);
        mNanoTicks = tKT.count();
    }
}

void NanosecondTime::hecto(const SQWORD hns)
{
    mNanoTicks = hns * 100LL;
}

Nanoseconds NanosecondTime::current()
{
    std::chrono::nanoseconds tKT;
    std::chrono::time_point tTPnow = std::chrono::system_clock::now();
    tKT = std::chrono::duration_cast<std::chrono::nanoseconds>(tTPnow.time_since_epoch());
    return tKT.count();
}

// static
Nanoseconds NanosecondTime::nanoYear(const WORD year)
{
    return Nanoseconds(DWORDF(year) * 365.2422) * 24LL * 3600LL * nanoFactor();
}

std::time_t NanosecondTime::epochSTT(const Nanoseconds tick)
{
    std::time_t result;
    std::chrono::time_point<std::chrono::system_clock,
                            std::chrono::duration<Nanoseconds> >
        tTPns( (std::chrono::duration<Nanoseconds>(tick)) );
    result = std::chrono::system_clock::to_time_t(tTPns);
    return result;
}

Nanoseconds NanosecondTime::offset(const StructTM other)
{
    std::time_t tSTTbase = epochSTT();
    std::time_t tSTTother = other.timeT();
    return Nanoseconds(tSTTother) - Nanoseconds(tSTTbase);
}



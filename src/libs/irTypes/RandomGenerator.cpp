#include "RandomGenerator.h"

#include <QDateTime>
#include <QTimer>

RandomGenerator::RandomGenerator(QObject *parent)
    : QObject{parent}
    , mGenerator(QRandomGenerator64::securelySeeded())
{
    setObjectName("RandomGenerator");
    initialize();
}

RandomGenerator::RandomGenerator(const DWORD seed, QObject *parent)
    : QObject{parent}
    , mGenerator(seed)
{
    setObjectName("RandomGenerator");
    initialize();
}

void RandomGenerator::initialize()
{
    emit initialized();
    QTimer::singleShot(10, &RandomGenerator::loadIntegers);
    QTimer::singleShot(100, &RandomGenerator::loadFloats);
}

void RandomGenerator::loadInteger(const Count min)
{
    Count tLoadCount = qMax(mLoadCount, min);
    mIntegerList.reserve(tLoadCount);
    while (integerCount() < tLoadCount)
        mIntegerList.append(mGenerator.generate64());
    emit loadedInteger(integerCount());
    QTimer::singleShot(20, &RandomGenerator::checkCounts);
}

void RandomGenerator::loadFloat(const Count min)
{
    Count tLoadCount = qMax(mLoadCount, min);
    mFloatList.reserve(tLoadCount);
    while (floatCount() < tLoadCount)
        mFloatList.append(mGenerator.generateDouble());
    emit loadedFloat(floatCount());
    QTimer::singleShot(20, &RandomGenerator::checkCounts);
}

void RandomGenerator::loadIntegers()
{
    loadInteger();
}

void RandomGenerator::loadFloats()
{
    loadFloat();
}

void RandomGenerator::checkCounts()
{
    if (integerCount() < mLowCount)
    {
        while (integerCount() < mLoadCount)
            mIntegerList.append(mGenerator.generate64());
        emit loadedInteger(integerCount());
    }
    if (floatCount() < mLowCount)
    {
        while (floatCount() < mLoadCount)
            mFloatList.append(mGenerator.generateDouble());
        emit loadedFloat(floatCount());
    }
}

BYTE RandomGenerator::byte() { return BYTE(take()); }
WORD RandomGenerator::word() { return WORD(take()); }
DWORD RandomGenerator::dword() { return DWORD(take()); }
QWORD RandomGenerator::qword() { return take(); }
OWORD RandomGenerator::oword() { return (OWORD(take()) << 64) | OWORD(take()); }
WORDF RandomGenerator::wordF() { return WORDF(takeF()); }
FLOAT RandomGenerator::dwordF()  { return takeF(); }

QWORD RandomGenerator::take()
{
    QWORD result = 0;
    loadInteger(1);
    Q_ASSERT( ! isIntegerEmpty());
    result = mIntegerList.takeFirst();
    emit taken(result, integerCount());
    QTimer::singleShot(20, &RandomGenerator::checkCounts);
    return result;
}

FLOAT RandomGenerator::takeF()
{
    FLOAT result = 0.0;
    loadFloat(1);
    Q_ASSERT( ! isFloatEmpty());
    result = mFloatList.takeFirst();
    emit taken(result, floatCount());
    QTimer::singleShot(20, &RandomGenerator::checkCounts);
    return result;
}


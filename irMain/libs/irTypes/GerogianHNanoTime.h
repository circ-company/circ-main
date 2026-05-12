#pragma once

#include <QDateTime>

#include "NetworkMacAddress.h"
#include "Types.h"

class GerogianHNanoTime
{
public:
    GerogianHNanoTime();

public: // const
    SQWORD hnano() const;
    WORD sequence() const;

public: // non-const
    SQWORD generate(const NetworkMacAddress mac, const QDateTime dttm);
    SQWORD generate(const NetworkMacAddress mac, const SQWORD timeStampMSec);

public: // static
    static SQWORD gregorianOffsetHNanoSec();
    static SQWORD currentHNanoSec();

private:
    SQWORD mCurrentHNanoTick;
    WORD mCurrentSequence;
    NetworkMacAddress mCurrentMacAddress;
    SQWORD mLastHNanoTick;
    WORD mLastSequence;
    NetworkMacAddress mLastMacAddress;
};

inline SQWORD GerogianHNanoTime::hnano() const { return mCurrentHNanoTick; }
inline WORD GerogianHNanoTime::sequence() const { return mCurrentSequence; }

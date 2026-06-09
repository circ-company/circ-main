#pragma once

#include <QSharedDataPointer>

#include <QMultiMap>
#include <QVariant>
#include <QVariantList>

#include "CodeContext.h"
#include "NanosecondTime.h"
#include "StatusLevel.h"
#include "StatusCode.h"


class Result
{
public: // types

public: // ctors
    Result(const CodeContext &ctx);

public: // const
    NanosecondTime time() const;
    CodeContext context() const;
    StatusLevel minLevel() const;
    StatusLevel maxLevel() const;
    Count statusCount() const;
    bool isValidStatusIndex(const Index ix) const;
    StatusCode status(const Index ix) const;
    StatusCode::List sortedStatus() const;
    StatusCode::List statusList(const StatusLevel lvl) const;

public: // non-const
    void clear();
    void add(const StatusCode &sts);
    void add(const StatusCode::List &stsl);

private:
    Nanoseconds mEpochNS=0;
    CodeContext mContext;
    StatusLevel mMinLevel;
    StatusLevel mMaxLevel;
    StatusCode::List mStatusCodeList;
    QMultiMap<StatusLevel, StatusCode> mLevelStatusMMap;
};

inline NanosecondTime Result::time() const { return NanosecondTime(mEpochNS); }
inline CodeContext Result::context() const { return mContext; }
//inline Severity Result::minSeverity() const { return mMinSeverity; }
//inline Severity Result::maxSeverity() const { return mMaxSeverity; }
inline Count Result::statusCount() const { return mStatusCodeList.count(); }
inline StatusCode::List Result::sortedStatus() const { return mLevelStatusMMap.values(); }
//inline StatusCode::List Result::statusList(const Severity sev) const { return mSevStatusMMap.values(sev); }


#pragma once

#include <Id.h>

#include <QMetaType>
#include <QMultiMap>
#include <QVariant>
#include <QVariantList>

#include <CodeContext.h>
#include <NanosecondTime.h>
#include <CodeLevel.h>
#include <TriBool.h>
#include <UidKeyMap.h>

#include "StatusCode.h"
#include "StatusItem.h"

class Result : public Id
{
public: // types

public: // ctors
    Result(const CodeContext &ctx);

public: // const
    NanosecondTime time() const;
    CodeContext context() const;
    CodeValue value() const;
    QVariant variant() const;
    bool isError() const;
    StatusLevel maxErrorLevel() const;
    StatusLevel maxStatusLevel() const;
    Count itemCount() const;
    bool isValidItemIndex(const Index ix) const;
    StatusItem item(const Index ix) const;
    StatusItem::List itemsByLevel() const;
    StatusItem::List
    items(const StatusLevel aMinLevel) const;

public: // non-const
    void clear();
    QVariant error(const CodeValue &aValue, const StatusLevel aLevel);
    QVariant success(const CodeValue &aValue, const StatusLevel aLevel);
    void add(const StatusItem &aItem);
    void add(const StatusItem::List &aItemList);

private:
    StatusItem item(const Uid aUid) const;
    void level(const StatusLevel aLevel);

private:
    Nanoseconds mEpochNS=0;
    CodeContext mContext;
    CodeValue mValue;
    bool mIsError;
    StatusLevel mLevel;
    StatusLevel mMaxErrorLevel;
    StatusLevel mMaxStatusLevel;
    UidKeyMap mUidKeyDMap;
    UidList mUidQueue;
    QMap<Uid, StatusItem> mUidItemMap;
    QMultiMap<StatusLevel, Uid> mLevelUidMMap;
};

inline NanosecondTime Result::time() const { return NanosecondTime(mEpochNS); }
inline CodeContext Result::context() const { return mContext; }
inline CodeValue Result::value() const { return mValue; }
inline QVariant Result::variant() const { return value().value(); }
inline bool Result::isError() const { return mIsError; }
inline StatusLevel Result::maxErrorLevel() const { return mMaxErrorLevel; }
inline StatusLevel Result::maxStatusLevel() const { return mMaxStatusLevel; }
inline Count Result::itemCount() const { return mUidQueue.count(); }


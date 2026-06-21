#include "Result.h"

Result::Result(const CodeContext &ctx)
    : mEpochNS(NanosecondTime::current()), mContext(ctx) {;}

bool Result::isValidItemIndex(const Index ix) const
{
    return ix >=0 && ix < Index(itemCount());
}

StatusItem Result::item(const Index ix) const
{
    StatusItem result;
    if (isValidItemIndex(ix))
    {
        const Uid cUid = mUidQueue.at(ix);
        const StatusItem cItem = item(cUid);
        result = cItem;
    }
    return result;
}

StatusItem::List Result::itemsByLevel() const
{
    StatusItem::List result;
    UidList cUidList = mLevelUidMMap.values();
    foreach (const Uid cUid, cUidList)
        result.append(item(cUid));
    return result;
}

StatusItem::List Result::items(const StatusLevel aMinLevel) const
{
    StatusItem::List result;
    UidList cUidList = mLevelUidMMap.values();
    foreach (const Uid cUid, cUidList)
    {
        const StatusItem cItem = item(cUid);
        if (cItem.level().value() >= aMinLevel.value())
            result.append(cItem);
    }
    return result;
}

void Result::clear()
{
    mEpochNS = 0;
    mIsError = false;
    mContext.clear();
    mMaxErrorLevel.invalidate();
    mMaxStatusLevel.invalidate();
    mUidKeyDMap.clear();
    mUidQueue.clear();
    mUidItemMap.clear();
    mLevelUidMMap.clear();
}

QVariant Result::error(const CodeValue &aValue, const StatusLevel aLevel)
{
    Q_ASSERT(aLevel.isWarn());
    mValue = aValue;
    level(aLevel);
    mIsError = true;
    return variant();
}

QVariant Result::success(const CodeValue &aValue, const StatusLevel aLevel)
{
    Q_ASSERT( ! aLevel.isWarn());
    mValue = aValue;
    level(aLevel);
    mIsError = false;
    return variant();
}

void Result::add(const StatusItem &aItem)
{
    const Uid cUid = aItem.uid();
    const StatusLevel cLevel = aItem.level();
    level(cLevel);
    mUidKeyDMap.insert(cUid, aItem.key());
    mUidQueue.append(cUid);
    mUidItemMap.insert(cUid, aItem);
    mLevelUidMMap.insert(cLevel, cUid);
}

void Result::add(const StatusItem::List &aItemList)
{
    foreach (const StatusItem cItem, aItemList) add(cItem);
}

StatusItem Result::item(const Uid aUid) const
{
    return mUidItemMap.value(aUid);
}

void Result::level(const StatusLevel aLevel)
{
    mLevel = aLevel;
    if (aLevel.isWarn())
        mMaxErrorLevel.max(aLevel.value());
    else
        mMaxStatusLevel.max(aLevel.value());
    mIsError |= aLevel.isWarn();
}


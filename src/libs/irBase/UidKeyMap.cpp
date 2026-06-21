#include "UidKeyMap.h"

UidKeyMap::UidKeyMap() {}

void UidKeyMap::insert(const Uid &aUid, const Key &aKey)
{
    mUidKeyDMap.insert(aUid, aKey);
}

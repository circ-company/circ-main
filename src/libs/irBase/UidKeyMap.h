#pragma once

#include <Uid.h>

#include <DualMap.h>

#include "Key.h"


class UidKeyMap
{
public:
    UidKeyMap();

public: // non-const
    void clear();
    void insert(const Uid &aUid, const Key &aKey);

private:
    DualMap<Uid, Key> mUidKeyDMap;
};

inline void UidKeyMap::clear() { mUidKeyDMap.clear(); }

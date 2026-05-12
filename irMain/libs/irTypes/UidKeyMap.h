#pragma once

#include <Uid.h>

#include <DualMap.h>

#include "Key.h"


class UidKeyMap
{
public:
    UidKeyMap();

private:
    DualMap<Uid, Key> mUidKeyDMap;
};

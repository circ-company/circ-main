#pragma once

#include <QMap>
#include "Key.h"
#include "Value.h"



class KeyValueMap : public QMap<Key, Value>
{
public:
    KeyValueMap();
};

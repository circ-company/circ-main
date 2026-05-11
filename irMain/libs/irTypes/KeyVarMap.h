#pragma once

#include <QMap>
#include <QVariant>
#include "Key.h"



class KeyVarMap : public QMap<Key, QVariant>
{
public:
    KeyVarMap();
};

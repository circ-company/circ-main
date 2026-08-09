#pragma once

#include "KeyMap.h"
#include "AText.h"

#include <QStringList>

KeyMapT<AText>
class KeyTextMap
{
public: // ctors
    KeyTextMap();

public: // debug
    QStringList toDebugStrings() const;
};

#pragma once

#include "Key.h"
#include <QList>

class KeyList : public Key::List
{
public: // ctors
    KeyList();
    KeyList(const QList<Key> &other);

public: // const

public: // non-const

public: // pointers
    KeyList & it() { return *this; }
    KeyList it() const { return *this; }
};




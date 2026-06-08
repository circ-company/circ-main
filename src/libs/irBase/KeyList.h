#pragma once

#include "Key.h"
#include "List.h"

class KeyList : public Key::List
{
public: // ctors
    KeyList();
    KeyList(const QList<Key> &other);

public: // const

public: // non-const

public: // pointers
    KeyList & it();
    KeyList it() const;

};

inline KeyList &KeyList::it() { return *this; }
inline KeyList KeyList::it() const { return *this; }

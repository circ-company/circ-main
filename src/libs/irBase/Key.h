#pragma once

#include "KeySegList.h"

#include <List.h>
#include <Types.h>

class Key : public KeySegList
{
public: // types
    typedef ListT<Key> List;

public: // ctors
    Key() {;}
    Key(const char * pch) : KeySegList(pch) {;}
    Key(const AText &atx) : KeySegList(atx) {;}
    Key(const KeySegList &other) : KeySegList(other) {;}
    Key(const QString &s) : KeySegList(s) {;}

public: // const
    QWORD hash64() const;

public: // static
    static char hinge();

};

inline char Key::hinge() { return '/'; }



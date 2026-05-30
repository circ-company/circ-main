#pragma once

#include "FSText.h"

class FSTextList : public FSText::List
{
public: // ctors
    FSTextList();
    FSTextList(const QByteArrayList &other);
    FSTextList(const FSText::List &other);

public: // const
    FSText join(const FSText fstx) const;
    QStringList toStringList() const;
    QStringList operator () () const;

public: // non-const
    void set(const QByteArrayList bal);
    void set(const QStringList qsl);
    void prependEach(const FSText &fstx);

public: // pointers
    FSTextList it() const;
    FSTextList & it();

};


inline QStringList FSTextList::operator ()() const { return toStringList(); }
inline FSTextList FSTextList::it() const { return *this; }
inline FSTextList &FSTextList::it() { return *this; }



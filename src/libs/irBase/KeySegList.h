#pragma once

#include "KeySeg.h"
#include "List.h"

#include <QString>
#include <QStringList>


class  KeySegList : public ListT<KeySeg>
{
public:
    KeySegList();
    KeySegList(const char * pch);
    KeySegList(const AText &at);
    KeySegList(const QString &s);
    KeySegList(const ListT<KeySeg> &other);

public: // const
    bool isNull() const;
    bool notEmpty() const;
    QString toString() const;
    QString toString(const QString &separator) const;
    operator QString() const;
    QString operator () () const;
    QStringList toStringList() const;
    operator QStringList() const;
    KeySeg toSeg() const;

public: // non-const
    void set();
    void set(const char * pch);
    void set(const AText &at);
    void set(const QString &s);
    void set(const ListT<KeySeg> &other);

public: // pointers
    KeySegList it() const;
    KeySegList & it();

protected: // static
    static char hinge();


};

inline bool KeySegList::isNull() const { return isEmpty(); }
inline bool KeySegList::notEmpty() const { return ! isEmpty(); }
inline KeySegList::operator QString() const { return toString(); }
inline QString KeySegList::operator ()() const { return toString(); }
inline void KeySegList::set() { clear(); }
inline void KeySegList::set(const char *pch) { set(AText(pch)); }
inline void KeySegList::set(const QString &s) { set(AText(s.toLocal8Bit())); }
inline KeySegList KeySegList::it() const { return *this; }
inline KeySegList &KeySegList::it()  { return *this; }
inline char KeySegList::hinge() { return ' '; }

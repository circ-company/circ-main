#pragma once

#include "KeySeg.h"

#include <QList>
#include <QString>
#include <QStringList>


class  KeySegList : public QList<KeySeg>
{
public:
    KeySegList();
    KeySegList(const char * pch);
    KeySegList(const AText &at);
    KeySegList(const QString &s);
    KeySegList(const QList<KeySeg> &other);

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
    KeySegList add(const KeySeg &aSeg) const;
    KeySegList operator + (const KeySeg &aSeg) const;

public: // non-const
    void set();
    void set(const char * pch);
    void set(const AText &at);
    void set(const QString &s);
    void set(const QList<KeySeg> &other);
    void operator += (const KeySeg &aSeg);

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
inline KeySegList KeySegList::operator + (const KeySeg &aSeg) const { return add(aSeg); }
inline void KeySegList::set() { clear(); }
inline void KeySegList::set(const char *pch) { set(AText(pch)); }
inline void KeySegList::set(const QString &s) { set(AText(s.toLocal8Bit())); }
inline void KeySegList::operator +=(const KeySeg &aSeg) { append(aSeg); }
inline KeySegList KeySegList::it() const { return *this; }
inline KeySegList &KeySegList::it()  { return *this; }
inline char KeySegList::hinge() { return '/'; }

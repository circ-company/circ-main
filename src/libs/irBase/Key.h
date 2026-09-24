#pragma once

#include "KeySegList.h"

#include <QList>
#include <QString>
class QVariant;

#include <Types.h>
#include <Url.h>
class QDir;
class Uid;

class Key : public KeySegList
{
public: // types
    typedef QList<Key> List;

public: // ctors
    Key() {;}
    Key(const char * pch) : KeySegList(pch) {;}
    Key(const AText &atx) : KeySegList(atx) {;}
    Key(const KeySegList &other) : KeySegList(other) {;}
    Key(const QList<KeySeg> &other) : KeySegList(other) {;}
    Key(const QString &s) : KeySegList(s) {;}
    Key(const QWORD &aQWord) : KeySegList(aQWord) {;}
    Key(const QDir &aDir) { set(aDir); }
    Key(const Url &aUrl) { set(aUrl); }

public: // const
    bool startsWith(const Key &start) const;
    bool isValidIndex(const Index ix) const;
    QVariant toVariant() const;
    QWORD hash64() const;
    Uid toUid() const;
    Key operator + (const KeySeg &aSeg) const;
    friend Key operator+(const Key &aKey, KeySeg &aSeg);

public: // non-const
    void set(const QDir &aDir);
    void set(const Url &aUrl, const bool aPathOnly=true);

public: // static
    static Key fromName(const QString aName);
    static char hinge();
};

inline bool Key::isValidIndex(const Index ix) const { return ix >= 0 && ix < count(); }
inline /*static*/ char Key::hinge() { return '/'; }



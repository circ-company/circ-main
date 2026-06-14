#pragma once

#include "CText.h"
#include <QList>

#include <QByteArrayList>
#include <QStringList>

class CTextList : public CText::List
{
public:
    CTextList();
    CTextList(const QByteArrayList &bal);
    CTextList(const QStringList &qsl);
    CTextList(const QString &s);
    CTextList(const AText::List &atxl);
    CTextList(const QList<CText> &other);

public: // const
    CText join(char ch=0) const;
    CText join(const CText hinge) const;
    QStringList toStringList() const;
    operator QStringList () const;


public: // non-const
    void set(const QByteArrayList &bal);
    void set(const QStringList &qsl);
    void set(const QString &s);
    void set(const AText::List &atxl);

public: // pointers
    CTextList it() const;
    CTextList & it();

};


inline CTextList::operator QStringList() const { return toStringList(); }
inline CTextList CTextList::it() const { return *this; }
inline CTextList &CTextList::it() { return *this; }

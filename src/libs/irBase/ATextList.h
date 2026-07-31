#pragma once

#include "AText.h"

#include <QByteArray>
#include <QByteArrayList>
#include <QMap>
#include <QMetaType>
#include <QMultiMap>
#include <QPair>
#include <QStringList>

class ATextList : public AText::List
{
public: // types
    typedef QList<AText::Pair>  PairList;
    typedef QMap<AText, AText>  PairMap;
    typedef QMultiMap<AText, AText>  PairMMap;

public: // ctors
    ATextList(const AText::List &other);
    ATextList(const QByteArrayList &other);
    ATextList(const QStringList &other);
    ATextList(const AText &atx, const char ch=0);
    ATextList & operator = (const AText::List &other);

public: // const
    AText join(const AText atx) const;
    PairList splitPairs(const char ch) const;
    QStringList toStringList() const;

public: // non-const
    void set(const QByteArrayList &other);
    void set(const QStringList &other);
    ATextList split(const AText &atx, const char ch);
    void prependEach(const AText &atx);

public: // pointers

public: // static
    static ATextList hexDump(const QByteArray &ba);
    static ATextList toList(const PairList atxlpr, const char assign='=');
    static ATextList toList(const PairMMap atxlMm, const char assign='=');

private: // static
    static AText hexDumpFullLine(const Index ix, const QByteArray &ba);
    static AText hexDumpPartLine(const Index ix, const QByteArray &ba);

public: // QMetaType
    ATextList it() const;
    ATextList & it();
    ATextList() = default;
    ~ATextList() = default;
    ATextList(const ATextList &) = default;
    ATextList &operator=(const ATextList &) = default;
};

Q_DECLARE_METATYPE(ATextList);

inline ATextList ATextList::it() const { return *this; }
inline ATextList &ATextList::it() { return *this; }

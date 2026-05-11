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
    ATextList & operator = (const AText::List &other);

public: // const
    AText join(const AText atx) const;
    PairList split(const char ch) const;

public: // non-const

public: // pointers
    ATextList it() const;
    ATextList & it();

public: // static
    static ATextList hexDump(const QByteArray &ba);
    static ATextList toList(const PairList atxlpr, const char assign='=');
    static ATextList toList(const PairMMap atxlMm, const char assign='=');

private: // static
    static AText hexDumpFullLine(const Index ix, const QByteArray &ba);
    static AText hexDumpPartLine(const Index ix, const QByteArray &ba);

public: // QMetaType
    ATextList() = default;
    ~ATextList() = default;
    ATextList(const ATextList &) = default;
    ATextList &operator=(const ATextList &) = default;
};

Q_DECLARE_METATYPE(ATextList);

inline ATextList ATextList::it() const { return *this; }
inline ATextList &ATextList::it() { return *this; }

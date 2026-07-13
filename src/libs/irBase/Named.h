/*! @file Named.h Declarations for Named Type template
  *
  */
#pragma once

#include "CText.h"
#include "CTextList.h"
#include "DualMap.h"
#include "Types.h"

/*! @class  Named
  * @brief  Specializes DualMap for case insensitive strings
  */
template <class T> class Named
{
public:
    typedef QList<T> TList;

public: // ctors
    Named(void) {;}

public: // const
    bool isEmpty(void) const { return mNameTDMap.isEmpty(); }
    int size(void) const { return mNameTDMap.size(); }
    bool contains(const T & t) const { return mNameTDMap.contains(t); }
    bool contains(const CText &name) const { return mNameTDMap.contains(name); }
    CText name(const T & t) const { return mNameTDMap.a(t); }
    T value(const CText &name) const { return mNameTDMap.b(name); }
    T value(const T &t) const { return mNameTDMap.a(t); }
    void insert(const T & t, const CText &name) { mNameTDMap.insert(name, t); }
    T first(const T & t1) const { (void)t1; return isEmpty() ? T() : mNameTDMap.constBegin().key(); }
    CTextList names(void) const { return mNameTDMap.aList(); }
    TList values() const { return mNameTDMap.bList(); }
    CText firstName() const { return mNameTDMap.firstA(); }
    CText lastName() const { return mNameTDMap.lastA(); }
    T firstValue() const { return mNameTDMap.firstB(); }
    T lastValue() const { return mNameTDMap.lastB(); }

public: // non-const
    void clear(void) { mNameTDMap.clear(); }
    void remove(const T & t) { mNameTDMap.remove(t); }
    void remove(const QString & name) { mNameTDMap.remove(name); }

public: // static
    static T invalid(void) { return T(); }

private:
    DualMap<CText,T> mNameTDMap;
};

typedef Named<INT> NamedInt;

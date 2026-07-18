#pragma once

#include <QList>
#include <QMetaType>

#include <KeySegMap.h>

#include "Option.h"
class ExeSupport;

class Options
{
public: // types
    typedef QList<QCommandLineOption> List;

public: // ctors
    Options(ExeSupport * pExe);

public: // const
    bool contains(const KeySeg &aName);
    List optionList() const;

public: // non-const
    bool add(const Option &aOpt, const bool aOverride=false);
    bool remove(const KeySeg &aName);

public: // pointers
    ExeSupport * exe();
    const Option opt(const KeySeg &aName) const;
    Option & opt(const KeySeg &aName);

public: // debug

private:
    ExeSupport * mpExeSupport=nullptr;
    KeySegMapT<Option> mNameOptionMap;

public: // QMetaType
    Options() = default;
    ~Options() = default;
    Options(const Options &) = default;
    Options &operator=(const Options &) = default;
    Options & it() { return *this; }
    const Options & it() const { return *this; }
};

Q_DECLARE_METATYPE(Options);

inline bool Options::contains(const KeySeg &aName) { return mNameOptionMap.contains(aName); }
inline ExeSupport *Options::exe() { Q_CHECK_PTR(mpExeSupport);  return mpExeSupport; }





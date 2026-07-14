#pragma once

#include <QMetaType>

#include <KeySegMap.h>

#include "Option.h"
class ExeSupport;

class Options
{

public: // types

public: // ctors
    Options(ExeSupport * pExe);

public: // const

public: // non-const

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

inline ExeSupport *Options::exe() { Q_CHECK_PTR(mpExeSupport);  return mpExeSupport; }





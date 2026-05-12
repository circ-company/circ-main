#pragma once

#include "TriBool.h"

class Null : private TriBool
{
public:
    Null();
    Null(const bool is);

public: // const
    bool null() const;
    bool full() const;


public: // non-const
    bool nullify();
    bool fullify();
};

inline bool Null::null() const { return TriBool::isTrue(); }
inline bool Null::full() const { return TriBool::isFalse(); }
inline bool Null::nullify() { TriBool::set(); return null(); }
inline bool Null::fullify() { TriBool::reset(); return null(); }

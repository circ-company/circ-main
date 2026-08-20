#pragma once

#include "TriBool.h"

#include <QMetaType>

class Null : public TriBool
{
public:
    Null(const bool is);

public: // const
    bool null() const;
    bool full() const;

public: // non-const
    bool nullify();
    bool fullify();

public: // QMetaType
    Null & it() { return *this; }
    const Null & it() const { return *this; }
    Null() = default;
    ~Null() = default;
    Null(const Null &) = default;
    Null &operator=(const Null &) = default;
};

Q_DECLARE_METATYPE(Null);

inline bool Null::null() const { return TriBool::isTrue(); }
inline bool Null::full() const { return TriBool::isFalse(); }
inline bool Null::nullify() { TriBool::set(); return null(); }
inline bool Null::fullify() { TriBool::reset(); return full(); }

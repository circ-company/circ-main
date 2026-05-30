#pragma once

#include <TriBool.h>

class Signum : public TriBool
{
public: // ctors
    Signum(); // invalid
    Signum(const signed sign);

public: // const
    bool invalid() const;
    bool positive() const;
    bool negative() const;
    bool zero() const;
    signed sign() const;

public: // non-const
    void set(const signed sign);
};

inline bool Signum::invalid() const { return ! valid() && ! value(); }
inline bool Signum::positive() const { return value() && valid(); }
inline bool Signum::negative() const { return cheap() && valid(); }
inline bool Signum::zero() const { return value() && invalid(); }


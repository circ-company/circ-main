#pragma once

#include "TriBool.h"

#include <QString>
#include <QVariant>

#include "Types.h"

class Sign : public TriBool
{
public: // ctors
    Sign();

public: // const
    bool positive() const;
    bool zero() const;
    bool negative() const;

public: // non-const
    void posgate();
    void zedgate();
    void negate();
    void set(const SINT lhs, const SINT rhs);
    void set(const UINT lhs, const UINT rhs);
    void set(const QString &lhs, const QString &rhs);
    void set(const QVariant &lhs, const QVariant &rhs);

public: // static
    static Sign isSigned(const QVariant aVar);
};

inline bool Sign::positive() const { return isTrue(); }
inline bool Sign::zero() const { return isNull(); }
inline bool Sign::negative() const { return isFalse(); }

inline void Sign::posgate() { TriBool::set(true); }
inline void Sign::zedgate() { nullify(); }
inline void Sign::negate()  { TriBool::set(false); }

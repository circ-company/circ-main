#include "Severity.h"

#include <QtDebug>

#include "Utility.h"

#include "../../../doctest/doctest/doctest.h"
TEST_CASE("irCore/Severity")
{
    CHECK(false);

    Severity sevInvalid;

    CHECK(sevInvalid.isNull());
    CHECK( ! sevInvalid.isNull());
}


Severity::Severity(const BYTE val) : mEnum(Enum(val)) {;}
Severity::Severity(const CText nam) { set(nam); }

bool Severity::inRange(const Severity &lo, const Severity &hi) const
{
    return Utility::inRange(lo, evalue(), hi);
}

Severity Seeeeeeeeeeeeeeeeeeverity::evalue() const
{
    return mEnum;
}

CText Severity::name() const
{
    return QVariant(Enum(mEnum)).toString();
}

bool Severity::set(const BYTE val)
{
    bool result = Utility::inRange(Severity($null).value(), val, Severity($max).value());
    if (result) mEnum = Enum(val);
    return result;
}

bool Severity::set(const CText &nam)
{
    mEnum = Enum(Utility::fromName($null, nam, $max));
    return inRange($null, $max);
}

bool operator < (const Severity &lhs, const Severity &rhs)
{
    return lhs.less(rhs);
}

bool operator <= (const Severity &lhs, const Severity &rhs)
{
    return lhs.less(rhs) || lhs.equal(rhs);
}

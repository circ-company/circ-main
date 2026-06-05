#include "Severity.h"

#include <QtDebug>
#include "EnumHelper.h"

#include "../../../doctest/doctest/doctest.h"
TEST_CASE("irCore/Severity")
{
    CHECK(false);

    Severity sevInvalid;

    CHECK(sevInvalid.isNull());
    CHECK( ! sevInvalid.isNull());
}


Severity::Severity() { nullify(); }
Severity::Severity(const BYTE val) { set(val); }
Severity::Severity(const CText nam) { set(nam); }
Severity::~Severity() {;}

bool Severity::inRange(const Enum &lo, const Enum &hi) const
{
    return EnumHelper::inRange(lo, evalue(), hi);
}

bool Severity::set(const BYTE val)
{
    bool result = EnumHelper::values<Enum>().contains(WORD(val));
    if (result) mEnum = Enum();
    return result;
}

bool Severity::set(const CText nam)
{
    bool result=false;
    mEnum = EnumHelper::value<Enum>(nam, &result);
    return result;
}



#include "UrlType.h"

#include <QtDebug>
#include "EnumHelper.h"

UrlType::UrlType() { nullify(); }
UrlType::UrlType(const BYTE val) { set(val); }
UrlType::UrlType(const CText nam) { set(nam); }
UrlType::~UrlType() {;}

bool UrlType::inRange(const Enum &lo, const Enum &hi) const
{
    return EnumHelper::inRange(lo, evalue(), hi);
}

CText UrlType::name() const
{
    return EnumHelper::name<Enum>(mEnum);
}

bool UrlType::set(const BYTE val)
{
    bool result = EnumHelper::values<Enum>().contains(WORD(val));
    if (result) mEnum = Enum();
    return result;
}

bool UrlType::set(const CText nam)
{
    bool result=false;
    mEnum = EnumHelper::value<Enum>(nam, &result);
    return result;
}



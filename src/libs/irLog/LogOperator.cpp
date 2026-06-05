#include "LogOperator.h"


#include <QtDebug>
#include "EnumHelper.h"

LogOperator::LogOperator() { nullify(); }
LogOperator::LogOperator(const BYTE val) { set(val); }
LogOperator::LogOperator(const CText nam) { set(nam); }
LogOperator::~LogOperator() {;}

bool LogOperator::inRange(const Enum &lo, const Enum &hi) const
{
    return EnumHelper::inRange(lo, evalue(), hi);
}

CText LogOperator::name() const
{
    return EnumHelper::name<Enum>(mEnum);
}

bool LogOperator::set(const BYTE val)
{
    bool result = EnumHelper::values<Enum>().contains(WORD(val));
    if (result) mEnum = Enum();
    return result;
}

bool LogOperator::set(const CText nam)
{
    bool result=false;
    mEnum = EnumHelper::value<Enum>(nam, &result);
    return result;
}



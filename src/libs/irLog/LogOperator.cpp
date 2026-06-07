#include "LogOperator.h"

#include <QtDebug>

#include "Utility.h"

LogOperator::LogOperator() { nullify(); }
LogOperator::LogOperator(const BYTE val) { set(val); }
LogOperator::LogOperator(const CText nam) { set(nam); }
LogOperator::~LogOperator() {;}

bool LogOperator::inRange(const Enum &lo, const Enum &hi) const
{
    return Utility::inRange(lo, evalue(), hi);
}

CText LogOperator::name() const
{
    return Utility::enumName(evalue());
}

bool LogOperator::set(const BYTE val)
{
    bool result = Utility::inRange(BYTE($null), val, BYTE($max));
    mEnum = result ? Enum(val) : $null;
    return result;
}

bool LogOperator::set(const CText nam)
{
    bool result = false;
    for (Index ix = $null; ix < $max && ! result; ++ix)
    {
        QVariant tVar;
        tVar.setValue((Enum(ix)));
        const CText cCtx = tVar.toByteArray();
        result = cCtx.like(nam, CText::Lower);
        if (result) set(ix);
    }
    return result;
}



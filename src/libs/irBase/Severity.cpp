#include "Severity.h"

#include <QtDebug>

#include "Utility.h"

Severity::Severity(const BYTE val) : mEnum(Enum(val)) {;}
Severity::Severity(const CText nam) { set(nam); }

bool Severity::inRange(const Severity &lo, const Severity &hi) const
{
    return Utility::inRange(lo, evalue(), hi);
}

Severity Severity::evalue() const
{
    return mEnum;
}

CText Severity::name() const
{
    const QVariant cVar((Enum(mEnum)));
    const QString cStr = cVar.toString();
//    qDebug() << Q_FUNC_INFO << cVar << cStr;
    return CText(cStr);
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

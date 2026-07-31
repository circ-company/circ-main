#include "Sign.h"

Sign::Sign() {;}

void Sign::set(const SINT lhs, const SINT rhs)
{
    if (lhs > rhs)  posgate();
    else if (rhs > lhs) negate();
    else zedgate();
}

void Sign::set(const UINT lhs, const UINT rhs)
{
    if (lhs > rhs)  posgate();
    else if (rhs > lhs) negate();
    else zedgate();
}

void Sign::set(const QString &lhs, const QString &rhs)
{
    if (lhs > rhs)  posgate();
    else if (rhs > lhs) negate();
    else zedgate();
}

void Sign::set(const QVariant &lhs, const QVariant &rhs)
{
    invalidate();
    Sign tSign = isSigned(lhs);
    switch (tSign.state())
    {
    case True:  set(lhs.toInt(),  rhs.toInt());         break;
    case False: set(lhs.toUInt(), rhs.toUInt());        break;
    case Null:  set(lhs.toString(), rhs.toString());    break;
    default:                                            break;
    }
}

// static
Sign Sign::isSigned(const QVariant aVar)
{
    Sign result;
    if (aVar.canConvert(QMetaType::fromType<SINT>()))       result.posgate();
    else if (aVar.canConvert(QMetaType::fromType<UINT>()))  result.negate();
    else                                                    result.zedgate();
    return result;
}

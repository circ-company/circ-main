#include "Aspect.h"


Aspect::Aspect(const int wd, const int ht) : Rational(wd, ht) {;}
Aspect::Aspect(const QRect rc) : Rational(rc.width(), rc.height()) {;}
Aspect::Aspect(const QSize sz) : Rational(sz.width(), sz.height()) {;}
Aspect::Aspect(const Rect rc) : Rational(rc.width(), rc.height()) {;}
Aspect::Aspect(const Size sz) : Rational(sz.width(), sz.height()) {;}
Aspect::Aspect(const SCRect scrc) : Rational(scrc.width(), scrc.height()) {;}

Aspect::Type Aspect::type() const
{
    Type result = $null;
    if (width() < height())         result = Tall;
    else if (width() > height())    result = Wide;
    else                            result = Square;
    return result;
}

Rational::Term Aspect::height(const Size sz) const
{
    return qRound(sz.heightF() * toReal());
}

Rational::Term Aspect::width(const Size sz) const
{
    return qRound(sz.widthF() * toReal());
}



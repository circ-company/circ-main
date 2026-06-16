#include "Rational.h"

//#include "Debug.h"

Rational::Term Rational::smInvalidTerm = INT_MIN;

Rational::Rational(const Term num, const Term den)
    : mNumerator(num), mDenominator(den) {;}
Rational::Rational(const qreal f, const signed int den)
    : mNumerator(qRound(f * qreal(den))), mDenominator(den) {;}



bool Rational::isReal() const
{
    return 0 != d();
}

signed int Rational::ratio() const
{
    if (notValid()) return INT_MIN;
    return n() / d();
}



Rational Rational::multiplied(const Term aNum) const
{
    Rational result(*this);
    result.n(n() * aNum);
    return result;
}

Rational::Term Rational::scaled(const Term aNum) const
{
    Term result = invalidTerm();
    if (isValid(aNum) && isReal())
    {
        Rational tRat =  multiplied(aNum);
        result = tRat.toInt();
        //TRACE << result << *this << aNum << tRat;
    }
    return result;
}

Rational Rational::divided(const Term aDen) const
{
    Rational result(*this);
    result.d(d() * aDen);
    return result;
}

Rational::Term Rational::toInt() const
{
    return isReal() ? qRound(toReal()): smInvalidTerm;
}

qreal Rational::toReal() const
{
    return isReal() ? (qreal(n()) / qreal(d())): qQNaN();
}

bool Rational::equal(const Rational rhs) const
{
    const Term l = n() * rhs.d();
    const Term r = rhs.n() * d();
    return l == r;
}

bool Rational::less(const Rational rhs) const
{
    const Term l = n() * rhs.d();
    const Term r = rhs.n() * d();
    return l < r;
}



void Rational::adjustDenominator(const Term aDen)
{
    if (isReal() && aDen != d())
    {
        n(qRound(toReal() * aDen));
        d(aDen);
    }
}

void Rational::add(const Rational aRat)
{
    if (d() == aRat.d())
    {
        n(n() + aRat.n());
    }
    else
    {
        signed tDen = d() * aRat.d();
        signed tNum = d() * aRat.n() + n() * aRat.d();
        set(tNum, tDen);
    }
}

bool Rational::isValid(const Term aTerm)
{
    return aTerm != smInvalidTerm;
}

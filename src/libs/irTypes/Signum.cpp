#include "Signum.h"

#include <climits>

Signum::Signum() { invalidate(); }
Signum::Signum(const signed int sign) { set(sign); }

signed int Signum::sign() const
{
    signed result = INT_MIN;
    if (positive())         result = + 1;
    else if (zero())        result = 0;
    else if (negative())    result = - 1;
    else {;} // is invalid
    return result;
}


void Signum::set(const signed int sign)
{
    if (0 == sign)
        mValue = true, mValid = false;
    else if (sign > 0)
        mValue = true, mValid = true;
    else // (sign < 0)
        mValue = false, mValid = true;
}


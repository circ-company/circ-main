#include "TriBool.h"

TriBool::TriBool(const bool is) : mValue(is), mValid(true) {;}

TriBool::State TriBool::state() const
{
    State  result = $null;
    if (isTrue())           result = True;
    else if (isFalse())     result = False;
    else if (isNull())      result = Null;
    else if (isInvalid())   result = Invalid;
    return result;
}

void TriBool::expect(const bool is)
{
    if ( ! is) reset();
}

bool TriBool::andEqual(const TriBool &other)
{
    if (valid() && other.valid())
        set(value() && other.value());
    return isTrue();
}









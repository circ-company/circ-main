#include "TriBool.h"

TriBool::TriBool() : mValue(false), mValid(false) {;}
TriBool::TriBool(const bool is) : mValue(is), mValid(true) {;}

bool TriBool::andEqual(const TriBool &other)
{
    if (valid() && other.valid())
        set(value() && other.value());
    return isTrue();
}









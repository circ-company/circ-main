#include "IntType.h"

IntType::IntType() {;}
IntType::IntType(const int aId) : QMetaType(aId) {;}
IntType::IntType(const QMetaType &aOther) : QMetaType(aOther) {;}

TriBool IntType::isSigned() const
{
    TriBool result;
    /*-*/if (id() == QMetaType::Int)            result.set(true);
    else if (id() == QMetaType::Long)           result.set(true);
    else if (id() == QMetaType::LongLong)       result.set(true);
    else if (id() == QMetaType::Short)          result.set(true);
    else if (id() == QMetaType::SChar)          result.set(true);
    else if (id() == QMetaType::UInt)           result.set(false);
    else if (id() == QMetaType::ULong)          result.set(false);
    else if (id() == QMetaType::ULongLong)      result.set(false);
    else if (id() == QMetaType::UShort)         result.set(false);
    else if (id() == QMetaType::UChar)          result.set(false);
 // else leave result undefined for non-integral types
    return result;
}

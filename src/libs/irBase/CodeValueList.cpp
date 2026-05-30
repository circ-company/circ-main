#include "CodeValueList.h"

CodeValueList::CodeValueList() {}

bool CodeValueList::isValid(const Index ix) const
{
    return ix >= 0 && ix < count();
}

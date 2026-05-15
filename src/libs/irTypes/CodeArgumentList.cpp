#include "CodeArgumentList.h"

CodeArgumentList::CodeArgumentList() {}

bool CodeArgumentList::isValid(const Index ix) const
{
    return ix >= 0 && ix < count();
}

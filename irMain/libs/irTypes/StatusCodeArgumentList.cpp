#include "StatusCodeArgumentList.h"

StatusCodeArgumentList::StatusCodeArgumentList() {}

bool StatusCodeArgumentList::isValid(const Index ix) const
{
    return ix >= 0 && ix < count();
}

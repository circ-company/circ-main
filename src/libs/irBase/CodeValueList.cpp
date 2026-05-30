#include "CodeValueList.h"

CodeValueList::CodeValueList() {}

bool CodeValueList::isValid(const Index ix) const
{
    return ix >= 0 && ix < count();
}

void CodeValueList::set(const Index ix, const CodeValue &cv)
{
    if (ix < 0) return;                                                 /*/===\*/
    if ( ! isValid(ix))
    {
        Index ix2 = count();
        while (ix2 < ix)
            append(cv);
    }
    replace(ix, cv);
}

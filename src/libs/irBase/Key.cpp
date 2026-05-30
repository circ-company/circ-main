#include "Key.h"

#include "Types.h"

bool Key::startsWith(const Key &start) const
{
    for (Index ix = 0; ix < start.count(); ++ix)
        if ( ! isValidIndex(ix) || at(ix) != start.at(ix))
            return false;
    return true;
}

QWORD Key::hash64() const
{
    union
    {
        QWORD qw;
        WORD w[4];
    } tUnion;
    tUnion.qw = 0uLL;
    KeySegList tSegments = it();
    Index tWordIndex = countof(tUnion.w) - 1;
    while (tSegments.notEmpty())
    {
        const KeySeg tSeg = tSegments.takeLast();
        const WORD tHash16 = tSeg.hash16();
        tUnion.w[tWordIndex] ^= tHash16;
        if (tWordIndex) --tWordIndex;
    }
    return tUnion.qw;
}

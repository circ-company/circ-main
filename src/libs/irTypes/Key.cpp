#include "Key.h"

#include "irBase.h"
#include "Types.h"

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

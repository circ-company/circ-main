#include "Key.h"

#include "Types.h"

QWORD Key::hash64() const
{
    QWORD result = 0;
    union
    {
        QWORD qw;
        WORD w[4];
    } tUnion;
    tUnion.qw = 0uLL;
    KeySegList tSegments = it();
    if (tSegments.count() < 5)
    {
        for (Index ix = 0; ix < tSegments.count(); ++ix)
            tUnion.w[3-ix] = qHash(tSegments.takeFirst());
    }
    Index tPosition = 3;
    while (tSegments.notEmpty())
    {
        const KeySeg tSeg = tSegments.takeLast();
        const WORD tHash16 = tSeg.hash16();
    }
    return result;
}

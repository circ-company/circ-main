#include "ColorWheel.h"

#include <QColor>

ColorWheel::ColorWheel(const Count aCount)
{
    if (aCount) initialize(aCount);
}

void ColorWheel::initialize(const Count aCount)
{
    fill(aCount);
}


void ColorWheel::opacityF(const qreal aReal)
{
    mOpacityF = aReal;
    for (Index ix = 0; ix < Index(size()); ++ix)
    {
        Color tColor = mListOfTs.value(ix);
        tColor.opaF(aReal);
        mListOfTs.replace(ix, tColor);
    }
}

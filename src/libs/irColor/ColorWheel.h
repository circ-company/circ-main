#pragma once

#include <Loop.h>
#include "Color.h"

#include <Types.h>

class ColorWheel : public LoopT<Color>
{
public: // ctors
    explicit ColorWheel(const Count aCount=256);

public: // const

public: // non-const
    void opacityF(const qreal aReal);
    void initialize(const Count aCount=256);

public: // pointers

private:
    qreal mOpacityF=1.0;
};





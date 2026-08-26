#include "Button.h"

ButtonT::ButtonT(const Size aSize, const char *pchSvgColor)
    : mSize(aSize) { set(pchSvgColor); }

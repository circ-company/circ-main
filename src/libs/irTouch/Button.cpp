#include "Button.h"

Button::Button(const Size aSize, const char *pchSvgColor)
    : mSize(aSize) { set(pchSvgColor); }

Button::Button(const Size aSize, const Color aColor)
    : mSize(aSize) { set(aColor); }

QPixmap Button::flat() const
{
    QPixmap result(mSize);
    result.fill(mBaseColor());
    return result;
}

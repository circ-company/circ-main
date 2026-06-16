#include "Size.h"

#include "Aspect.h"
#include "SCRect.h"

Size::Size(const bool null) : QSize(null ? 0 : -1, null ? 0 : -1) {;}
Size::Size(const QSize other) : QSize(other) {;}
Size::Size(const int w, const int h) : QSize(w, h) {;}
Size::Size(const int dim) : QSize(dim, dim) {;}
Size::Size(const int dim, const Aspect aspect) { set(dim, aspect); }
Size::Size(const Size &other) : QSize(other) {;}
Size::Size(const Size outside, const Aspect aspect) { set(outside, aspect); }

unsigned int Size::area() const
{
    return isValid() ? (width() * height()) : 0;
}

bool Size::isValidIndex(const int index) const
{
    return (index >= 0 && index <= int(area()));
}

Point Size::center() const
{
    return Point(width() / 2, height() / 2);
}

int Size::index(const Point pt) const
{
    return isValid() ? ((pt.y() * width()) + pt.x()) : -1;
}

Point Size::position(const int index) const
{
    Point result;
    if (isValid() && isValidIndex(index))
    {
        result.setX(index % width());
        result.setY(index / width());
    }
    return result;
}

bool Size::less(const Size &rhs) const
{
    return area() < rhs.area();
}

bool Size::isEqualAspect(const Size &rhs) const
{
    const Aspect cLt(it());
    const Aspect cRt(rhs);
    return cLt == cRt;
}

Size Size::expanded(const Size sz) const
{
    return Size(width() + sz.width(), height() + sz.height());
}

Size Size::expanded(const unsigned int u) const
{
    return Size(width() + u, height() + u);
}

Size Size::trimmed(const unsigned int modulo) const
{
    const unsigned cMask = ~ (modulo - 1);
    return Size(width() & cMask, height() & cMask);
}

Size Size::scaled(const unsigned int u) const
{
    return Size(width() * u, height() * u);
}

Size Size::scaled(const qreal f) const
{
    return Size(width() * f, height() * f);
}

qreal Size::scaleToF(const Size &rhs) const
{
    return qMin(qreal(width()) / qreal(rhs.width()),
                qreal(height()) / qreal(rhs.height()));
}

Size Size::unioned(const Size &rhs) const
{
    const SCRect cOurRect(it());
    const SCRect cRhsRect(rhs);
    return cOurRect.toQRect().united(cRhsRect).size();
}

Size Size::intersected(const Size &rhs) const
{
    const SCRect cOurRect(it());
    const SCRect cRhsRect(rhs);
    return cOurRect.toQRect().intersected(cRhsRect).size();
}

Aspect Size::aspect() const
{
    return Aspect(width(), height());
}

Size Size::set(const Size outside, const Aspect aspect)
{
    Size result;
    const int cWidth  = aspect.width(outside);
    const int cHeight = aspect.height(outside);
    result.set(cWidth, cHeight);
    return set(result);
}

Size Size::unionWith(const Size &rhs)
{
    return it() = unioned(rhs);
}

Size Size::intersectedWith(const Size &rhs)
{
    return it() = intersected(rhs);
}

Size Size::operator =(const Size &rhs)
{
    if (rhs.isValid())
        set(rhs.width(), rhs.height());
    return it();
}


Size Size::set(const int w, const int h)
{
    QSize::setWidth(w), QSize::setHeight(h);
    return it();
}

Size Size::set(const int dim, const Aspect aspect)
{
    return Size(Size(dim), aspect);
}

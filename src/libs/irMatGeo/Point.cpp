#include "Point.h"

#include <QPoint>

#include <TriBool.h>

#include "Size.h"

Point::Point(const bool zero) { set(zero ? Point(0,0) : nullPoint()); }
Point::Point(const QPoint &other) : mX(other.x()), mY(other.y())  {;}
Point::Point(const int aX, const int aY)  : mX(aX), mY(aY)  {;}
Point::Point(const Size aSize, const Index aIndex) { set(aSize, aIndex); }

bool Point::isNull() const
{
    return equals(nullPoint());
}

Index Point::index(const Size aSize)
{
    Index result = 0;
    result += y() * aSize.width();
    result += x();
    return result;
}

TriBool Point::equals(const Point &rhs) const
{
    TriBool result;
    if  (valid() && rhs.valid())
        result.set(x() == rhs.x() && y() == rhs.y());
    return result;
}

bool Point::less(const Point &rhs) const
{
    return (x() < rhs.x()) ? true : (y() < rhs.y());
}

Point Point::added(const Point &rhs) const
{
    return Point(int(x() + rhs.x()), int(y() + rhs.y()));
}

Point Point::multiplied(const Size &rhs) const
{
    return Point(x() * rhs.width(), y() * rhs.height());
}

Point::Sortable Point::sortable() const
{
    DWORD result = 0;
    result |=  DWORD(y()) & 0x0000FFFF;
    result |= (DWORD(x()) & 0x0000FFFF) << 16;
    return Sortable(result);
}

QPoint Point::toQPoint() const
{
    return QPoint(x(), y());
}

Point Point::set(const Point aPt)
{
    return set(aPt.x(), aPt.y());
}

Point Point::set(const Index aX, const Index aY)
{
    x(aX), y(aY);
    return it();
}

Point Point::set(const Size sz, const Index ix)
{
    Point result;
    if (sz.isValid() && ! sz.isEmpty())
    {
        const unsigned cWidth = sz.width();
        const unsigned cY = ix / cWidth;
        const unsigned cX = ix % cWidth;
        result = Point(cX, cY);
    }
    return it() = result;
}

void Point::move(const Point aPt)
{
    x(x() + aPt.x()), y(y() + aPt.y());
}

void Point::modulo(const Size &aSz)
{
    x(x() % aSz.width()), y(y() % aSz.height());
}

void Point::nullify()
{
    set(nullPoint());
}

Point Point::nullPoint()
{
    return Point(INT_MIN, INT_MIN);
}


extern Point operator + (const Point lhs, const Point rhs)
{
    return Point(int(lhs.x() + rhs.x()),
                 int(lhs.y() + rhs.y()));
}

extern Point operator < (const Point lhs, const Point rhs)
{
    return lhs.less(rhs);
}



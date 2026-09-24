#pragma once

#include <QPoint>

#include <Types.h>
class Size;
class SCRect;
class TriBool;


class Point
{
public: // Types
    typedef WORD Sortable;

public: // ctors
    Point(const bool zero=false);
    Point(const QPoint &other);
    Point(const int x, const int aY);
    Point(const Size sz, const Index ix);

public: // const
    virtual bool isNull() const;
    virtual bool valid() const;
    bool isZero() const;
    Index index(const Size aSize);
    TriBool equals(const Point &rhs) const;
    bool less(const Point &rhs) const;
    bool edge(const SCRect &aRect) const;
    bool valid(const SCRect &aRect, const bool aEdgeOk=true) const;
    Point added(const Point &rhs) const;
    Point multiplied(const Size &rhs) const;
    Point up(const int d=1) const;
    Point nw(const int d=1) const;
    Point no(const int d=1) const;
    Point ne(const int d=1) const;
    Point we(const int d=1) const;
    Point ea(const int d=1) const;
    Point sw(const int d=1) const;
    Point so(const int d=1) const;
    Point se(const int d=1) const;
    int x() const;
    int y() const;
    int row() const;
    int col() const;
    Sortable sortable() const;
    QPoint toQPoint() const;
    Point operator * (const Size &rhs) const;
    bool operator < (const Point &rhs) const;
    QPoint operator () () const;
    friend Point operator + (const Point &lhs, const Point &rhs);
    friend Point operator < (const Point &lhs, const Point &rhs);

public: // non-const
    Point set(const Point aPt);
    Point set(const Index aX, const Index aY);
    Point set(const Size sz, const Index ix);
    void x(const int aX);
    void y(const int aY);
    void nullify();
    void move(const Point aPt);
    void modulo(const Size &aSz);
    Point operator %= (const Size &aSz);

public: // pointers
    Point it() const;
    Point & it();

public: // static
    static Point nullPoint();

private:
    SWORD mX=nullPoint().x();
    SWORD mY=nullPoint().y();
};

inline bool Point::valid() const { return ! isNull(); }
inline bool Point::isZero() const { return 0 == x() && 0 == y(); }
inline Point Point::up(const int d) const { return Point(x() + 0, y() + d); }
inline Point Point::nw(const int d) const { return Point(x() - d, y() - d); }
inline Point Point::no(const int d) const { return Point(x() + 0, y() - d); }
inline Point Point::ne(const int d) const { return Point(x() + d, y() - d); }
inline Point Point::we(const int d) const { return Point(x() - d, y() + 0); }
inline Point Point::ea(const int d) const { return Point(x() + d, y() + 0); }
inline Point Point::sw(const int d) const { return Point(x() - d, y() + d); }
inline Point Point::so(const int d) const { return Point(x() + 0, y() + d); }
inline Point Point::se(const int d) const { return Point(x() + d, y() + d); }
inline int Point::x() const { return mX; }
inline int Point::y() const { return mY; }
inline int Point::row() const { return y(); }
inline int Point::col() const { return x(); }
inline Point Point::operator *(const Size &rhs) const { return multiplied(rhs); }
inline bool Point::operator <(const Point &rhs) const { return less(rhs); }
inline QPoint Point::operator ()() const { return toQPoint(); }
inline void Point::x(const int aX) { mX = aX; }
inline void Point::y(const int aY) { mY = aY; }
inline Point Point::operator %=(const Size &aSz) { modulo(aSz); return it(); }
inline Point Point::it() const { return *this; }
inline Point &Point::it() { return *this; }

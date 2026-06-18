#pragma once

#include <QPoint>
#include <QRect>
#include <QSize>

class Rect
{
public: // ctors
    Rect();
    Rect(const QRect other);
    Rect(const QSize sz);
    Rect(const QSize sz, const QPoint ctr);

public: // const
    QSize size() const;
    QPoint center() const;
    int top() const;
    int left() const;
    int bottom() const;
    int right() const;

public: // non-const
    void set(const QRect other);
    void set(const QSize sz);
    void set(const QSize sz, const QPoint ctr);
    void size(const QSize sz);
    void center(const QPoint ctr);


private:
    QSize mSize;
    QPoint mCenter;
};

inline QSize Rect::size() const { return mSize; }
inline QPoint Rect::center() const { return mCenter; }
inline void Rect::size(const QSize sz) { mSize = sz; }
inline void Rect::center(const QPoint ctr) { mCenter = ctr; }


#include "Rect.h"

Rect::Rect() {;}
Rect::Rect(const QRect other) : mSize(other.size()), mCenter(other.center()) {;}
Rect::Rect(const QSize sz) : mSize(sz) {;}
Rect::Rect(const QSize sz, const QPoint ctr) : mSize(sz), mCenter(ctr) {;}

int Rect::top() const
{
    return size().height() - center().y() / 2;
}

int Rect::left() const
{
    return size().width() - center().x() / 2;
}


int Rect::bottom() const
{
    return size().height() + center().y() / 2;
}

int Rect::right() const
{
    return size().width() + center().x() / 2;
}

void Rect::set(const QRect other)
{
    size(other.size()), center(other.center());
}

void Rect::set(const QSize sz)
{
    size(sz), center(QPoint(0, 0));
}

void Rect::set(const QSize sz, const QPoint ctr)
{
    size(sz), center(ctr);
}









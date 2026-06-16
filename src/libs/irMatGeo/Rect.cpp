#include "Rect.h"

Rect::Rect(const Term t, const Term l, const Term b, const Term r) { set(t, l, b, r); }
Rect::Rect(const Point tl, const Point br) { set(tl, br); }
Rect::Rect(const Point tl, const Size sz) { set(tl, sz); }
Rect::Rect(const Size sz, const Point ctr) { set(sz, ctr); }
Rect::Rect(const SCRect scrc) { set(scrc); }

void Rect::set(const Size sz, const Point ctr)
{
    set(sz.height() - (ctr.row() >> 1),
        sz.width()  - (ctr.col() >> 1),
        sz.height() + (ctr.row() >> 1),
        sz.width()  + (ctr.col() >> 1));
}


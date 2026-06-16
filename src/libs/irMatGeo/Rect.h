#pragma once

#include <QMetaType>
#include <QRect>

#include "Point.h"
#include "SCRect.h"
#include "Size.h"

class Rect : public QRect
{
public: // types
    typedef int Term;

public: // ctors
    Rect(const Term t, const Term l, const Term b, const Term r);
    Rect(const Point tl, const Point br);
    Rect(const Point tl, const Size sz);
    Rect(const Size sz, const Point ctr);
    Rect(const SCRect scrc);

public: // const
    Term top() const;
    Term left() const;
    Term bottom() const;
    Term right() const;

public: // non-const
    void top(const Term t);
    void left(const Term l);
    void bottom(const Term b);
    void right(const Term r);
    void set(const Term t, const Term l, const Term b, const Term r);
    void set(const Point tl, const Point br);
    void set(const Point tl, const Size sz);
    void set(const Size sz, const Point ctr);
    void set(const SCRect scrc);

public: // pointers

private:
    Term mTop=-1;
    Term mLeft=-1;
    Term mBottom=-1;
    Term mRight=-1;

public: // QMetaType
    Rect() = default;
    ~Rect() = default;
    Rect(const Rect &) = default;
    Rect &operator=(const Rect &) = default;
    Rect & it() { return *this; }
    const Rect & it() const { return *this; }
};

inline Rect::Term Rect::top() const { return mTop; }
inline Rect::Term Rect::left() const { return mLeft; }
inline Rect::Term Rect::bottom() const { return mBottom; }
inline Rect::Term Rect::right() const { return mTop; }
inline void Rect::top(const Term t) { mTop = t; }
inline void Rect::left(const Term l) { mLeft = l; }
inline void Rect::bottom(const Term b) { mBottom = b; }
inline void Rect::right(const Term r) { mRight = r; }
inline void Rect::set(const Term t, const Term l, const Term b, const Term r) { top(t), left(l), bottom(b), right(r); }
inline void Rect::set(const Point tl, const Point br) { top(tl.row()), left(tl.col()), bottom(br.row()), right(br.col()); }
inline void Rect::set(const Point tl, const Size sz) { top(tl.row()), left(tl.col()), bottom(sz.height() + tl.row()), right(sz.width() + tl.col()); }
inline void Rect::set(const SCRect scrc) { set(scrc.size(), scrc.center()); }

Q_DECLARE_METATYPE(Rect);

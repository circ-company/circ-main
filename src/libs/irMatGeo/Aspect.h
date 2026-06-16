#pragma once

#include <QMetaType>
#include <QRect>
#include <QSize>

#include <Types.h>

#include "Rational.h"
#include "Rect.h"
#include "Size.h"
#include "SCRect.h"

class Aspect : public Rational
{
public: // types
    enum Type { $null = 0, Tall, Square, Wide };

public: // ctors
    Aspect(const int wd, const int ht);
    Aspect(const QRect rc);
    Aspect(const QSize sz);
    Aspect(const Rect rc);
    Aspect(const Size sz);
    Aspect(const SCRect scrc);

public: // const
    Term width() const;
    Term height() const;
    WORDF widthF() const;
    WORDF heightF() const;
    Type type() const;
    bool isSquare() const;
    bool isWide() const;
    bool isTall() const;
    Term width(const Size sz) const;
    Term height(const Size sz) const;

public: // non-const
    virtual void set(const int wd, const int ht) final;
    void set(const QRect rc);
    void set(const QSize sz);
    void set(const Rect rc);
    void set(const Size sz);
    void set(const SCRect scrc);

public:

public:

public: // QMetaType
    Aspect() = default;
    ~Aspect() = default;
    Aspect(const Aspect &) = default;
    Aspect &operator=(const Aspect &) = default;
    Aspect & it() { return *this; }
    const Aspect & it() const { return *this; }
};

inline Rational::Term Aspect::width() const { return n(); }
inline Rational::Term Aspect::height() const { return d(); }
inline WORDF Aspect::widthF() const { return width(); }
inline WORDF Aspect::heightF() const { return height(); }
inline bool Aspect::isSquare() const { return Square == type(); }
inline bool Aspect::isWide() const { return Wide == type(); }
inline bool Aspect::isTall() const { return Tall == type(); }
inline void Aspect::set(const int wd, const int ht) { Rational::set(wd, ht); }
inline void Aspect::set(const QRect rc) { Rational::set(rc.width(), rc.height()); }
inline void Aspect::set(const QSize sz) { Rational::set(sz.width(), sz.height()); }
inline void Aspect::set(const Rect rc) { Rational::set(rc.width(), rc.height()); }
inline void Aspect::set(const Size sz) { Rational::set(sz.width(), sz.height()); }
inline void Aspect::set(const SCRect scrc) { Rational::set(scrc.width(), scrc.height()); }

Q_DECLARE_METATYPE(Aspect);

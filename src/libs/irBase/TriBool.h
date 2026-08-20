#pragma once

#include <QMetaType>

class TriBool
{
public: // ctors
    enum State
    {
        $null       = 0,
        Invalid     = 11,
        Null        = 12,
        False       = 21,
        True        = 22,
    };

public: // ctors
    TriBool(const bool is);

public: // const
    bool value() const;
    bool valid() const;
    bool cheap() const;
    bool invalid() const;
    bool isTrue() const;
    bool isFalse() const;
    bool isNull() const;
    bool isInvalid() const;
    State state() const;
    operator bool () const;

public: // non-const
    void set(const bool is=true);
    void expect(const bool is);
    void reset();
    void truify();
    void falsify();
    void nullify();
    void invalidate();
    bool andEqual(const TriBool &other);
    bool operator &= (const TriBool &other);

protected:
    bool mValue = false;
    bool mValid = false;

public: // QMetaType
    TriBool & it() { return *this; }
    const TriBool & it() const { return *this; }
    TriBool() = default;
    ~TriBool() = default;
    TriBool(const TriBool &) = default;
    TriBool &operator=(const TriBool &) = default;
};

Q_DECLARE_METATYPE(TriBool);

inline bool TriBool::value() const { return mValue; }
inline bool TriBool::valid() const { return mValid; }
inline bool TriBool::cheap() const { return ! value(); }
inline bool TriBool::invalid() const { return ! valid(); }
inline bool TriBool::isTrue() const { return value() && valid(); }
inline bool TriBool::isFalse() const { return cheap() && valid(); }
inline bool TriBool::isNull() const { return value() && invalid(); }
inline bool TriBool::isInvalid() const { return cheap() && invalid(); }
inline TriBool::operator bool() const { return isTrue(); }
inline void TriBool::set(const bool is) { mValue = is, mValid = true; }
inline void TriBool::reset() { set(false); }
inline void TriBool::truify() { set(true); }
inline void TriBool::falsify() { reset(); }
inline void TriBool::nullify() { mValue = true, mValid = false; }
inline void TriBool::invalidate() { mValue = false, mValid = false; }
inline bool TriBool::operator &=(const TriBool &other) { return andEqual(other); }



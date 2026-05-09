#pragma once

#include "AText.h"

class XText : public AText
{
public: // ctors
    XText();
    XText(const char * pch);
    XText(const QByteArray &ba);
    XText(const QString &s);
    XText(const void * p, const Count k);


public: // non-const
    void set(const void * p, const Count k);

public: // pointers
    XText it() const;
    XText & it();

public: // static
    static char hinge();
    static void hinge(const char ch);

protected: // static
    bool isValidFirst(const char ch) const override;
    bool isValidChar(const char ch) const override;

private:
    static char smHingeChar;

private:

};

inline XText XText::it() const { return *this; }
inline XText & XText::it() { return *this; }
inline char XText::hinge() { return smHingeChar; }
inline void XText::hinge(const char ch) { smHingeChar = ch; }




#pragma once

#include "AText.h"

#include <QList>


class FSText : public AText
{
public: // types
    typedef QList<FSText> List;

public: // ctors
    FSText();
    FSText(const char * pch);
    FSText(const QByteArray &ba);
    FSText(const QString &s);

public: // static
    static char hinge();
    static void hinge(const char ch);

protected: // static
    bool isValidFirst(const char ch) const override;
    bool isValidChar(const char ch) const override;

private: // pointers
    FSText it() const;
    FSText & it();

private:
    static char smHingeChar;

private:

};


inline FSText FSText::it() const { return *this; }
inline FSText & FSText::it() { return *this; }
inline char FSText::hinge() { return smHingeChar; }
inline void FSText::hinge(const char ch) { smHingeChar = ch; }



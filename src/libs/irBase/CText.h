#pragma once


#include "AText.h"

#include <QImage>
#include <QList>

/*! class CText Code Text
 *
 *  see: https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines.html#c128-virtual-functions-should-specify-exactly-one-of-virtual-override-or-final
 */
class  CText : public AText
{
public: // types
    typedef QList<CText> List;

public: // ctors
    CText();
    CText(const char * pch);
    CText(const QByteArray &ba);
    CText(const QByteArray &ba, const QChar repl);
    CText(const QString &s);
    CText(const QImage::Format &aQIF);

public: // non-const
    void set(const QImage::Format &aQIF);

public: // static
    static char hinge();
    static void hinge(const char ch);

protected: // static
    bool isValidFirst(const char ch) const;
    bool isValidChar(const char ch) const;

private: // pointers
    CText it() const;
    CText & it();

private:
    static char smHingeChar;

private:

};

inline CText CText::it() const { return *this; }
inline CText & CText::it() { return *this; }
inline char CText::hinge() { return smHingeChar; }
inline void CText::hinge(const char ch) { smHingeChar = ch; }



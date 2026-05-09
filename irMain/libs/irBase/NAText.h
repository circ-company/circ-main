#pragma once

#include "AText.h"

#include <QList>

#include "XText.h"

class NAText : public AText
{
public: // types
    typedef QList<NAText> List;

public: // ctors
    NAText();
    NAText(const char * pch);
    NAText(const QByteArray &ba);
    NAText(const QString &s);

public: // const
    XText toXText() const;

public: // static
    static char hinge();
    static void hinge(const char ch);

protected: // static
    bool isValidFirst(const char ch) const override;
    bool isValidChar(const char ch) const override;

private: // pointers
    NAText it() const;
    NAText & it();

private:
    static char smHingeChar;

private:

};

inline NAText NAText::it() const { return *this; }
inline NAText &NAText::it() { return *this; }

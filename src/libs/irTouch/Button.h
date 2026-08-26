/*! @file Button.h declaration of Button touch screen class
 */
#pragma once

#include <QColor>
#include <QIcon>
#include <QPixmap>

#include <Size.h>
#include <Types.h>
#include <UText.h>

#include "GenerateIconScheme.h"

class Button
{
public: // ctors
    Button(const Size aSize, const char * pchSvgColor);
    Button(const Size aSize, const Color aColor);

public: // const
    QPixmap flat() const;
    QIcon icon() const;
    QPixmap iconSet() const;

public: // non-const
    void set(const char * pchSvgColor);
    void set(const Color aColor);
    void scheme(const GenerateIconScheme aScheme);
    QIcon make(const UText aText);

public: // pointers
    GenerateIconScheme scheme() const;
    GenerateIconScheme & scheme();

private:
    Color mBaseColor;
    Size mSize;
    GenerateIconScheme mScheme;
    QPixmap mIconSet;
    QIcon mIcon;

};


inline void Button::set(const char *pchSvgColor) { mBaseColor = Color(pchSvgColor); }
inline void Button::set(const Color aColor) { mBaseColor = aColor; }
inline void Button::scheme(const GenerateIconScheme aScheme) { mScheme = aScheme; }


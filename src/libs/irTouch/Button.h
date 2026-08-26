/*! @file Button.h declaration of ButtonT template
 */
#pragma once

#include <QColor>
#include <QIcon>
#include <QPixmap>

#include <Size.h>
#include <Types.h>
#include <UText.h>

#include "GenerateIconScheme.h"

class ButtonT
{
public: // ctors
    ButtonT(const Size aSize, const char * pchSvgColor);

public: // const
    QIcon icon() const;
    QPixmap iconSet() const;

public: // non-const
    void set(const char * pchSvgColor);
    QIcon make(const UText aText);

public: // pointers
    GenerateIconScheme scheme() const;
    GenerateIconScheme & scheme();

private:
    Color mBaseColor;;
    Size mSize;
    GenerateIconScheme mScheme;
    QPixmap mIconSet;
    QIcon mIcon;

};


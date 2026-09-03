/*! @file ToolButton.h declaration of ToolButton touch screen class
 */
#pragma once

#include <QToolButton>

#include <QColor>
#include <QIcon>
#include <QPixmap>

#include <Size.h>
#include <Types.h>
#include <UText.h>


class ToolButton : public QToolButton
{
public: // ctors
    ToolButton(const UText aText,
               const QColor aColor,
               QWidget *parent=nullptr);
    ToolButton(const UText aText,
               const QColor aColor,
               const Size aSize,
               QWidget *parent=nullptr);

public: // const
    QPixmap flat() const;
    QIcon icon() const;
    QPixmap iconSet() const;

public: // non-const
    QIcon make();

public: // static
    static Size baseSize();
    static void baseSize(const Size aSize);

public: // pointers

private: // non-const
    QPixmap generate(const QIcon::Mode aMode,
                     const QIcon::State aState);

private:
    UText mText;
    QColor mBaseColor;
    Size mSize;
    QPixmap mIconSet;
    QIcon mIcon;
    static Size smBaseSize;
};

inline Size ToolButton::baseSize() { return smBaseSize; }
inline void ToolButton::baseSize(const Size aSize) { smBaseSize = aSize; }




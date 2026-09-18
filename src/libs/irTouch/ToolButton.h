/*! @file ToolButton.h declaration of ToolButton touch screen class
 */
#pragma once

#include <QToolButton>

#include <QIcon>
#include <QPixmap>

#include <Color.h>
#include <Size.h>
#include <Types.h>
#include <UText.h>


class ToolButton : public QToolButton
{
public: // ctors
    ToolButton(const UText aText,
               const UText aColorName,
               QWidget *parent=nullptr);
    ToolButton(const UText aText,
               const UText aColorName,
               const Size aSize,
               QWidget *parent=nullptr);

public: // const
    UText text() const;
    QPixmap flat() const;
    QIcon icon() const;

public: // non-const
    void set(const QIcon::Mode aMode,
             const QIcon::State mState=QIcon::Off);
    QIcon makeIcon();

public: // static

public: // pointers

private: // non-const
    QPixmap generatePixmapFor(const QIcon::Mode aMode,
                     const QIcon::State aState) const;

private:
    const Size cmButtonSize;
    UText mText;
    Color mBaseColor;
    QPixmap mIconSet;
    QIcon mIcon;
    QIcon::State mState=QIcon::State::Off;
    QIcon::Mode mMode=QIcon::Mode::Disabled;
};

inline UText ToolButton::text() const { return mText; }




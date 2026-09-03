#include "ToolButton.h"

#include <QFont>
#include <QPainter>
#include <QPaintEvent>

#include <Log.h>
#include <SCRect.h>

Size ToolButton::smBaseSize(96, 64);

ToolButton::ToolButton(const UText aText, const QColor aColor, QWidget *parent)
    : QToolButton(parent)
    , mText(aText)
    , mBaseColor(aColor)
    , mSize(baseSize())
{
    setFixedSize(mSize);
    setIconSize(mSize);
    setIcon(make());
}

ToolButton::ToolButton(const UText aText,
                       const QColor aColor,
                       const Size aSize,
                       QWidget * parent)
    : QToolButton(parent)
    , mText(aText)
    , mBaseColor(aColor)
    , mSize(aSize)
{
    setFixedSize(mSize);
    setIconSize(mSize);
    setIcon(make());
}

QPixmap ToolButton::flat() const
{
    QPixmap result(mSize);
    result.fill(mBaseColor);
    return result;
}

QIcon ToolButton::make()
{
    QIcon result;
    QPixmap tPxm0 = generate(QIcon::Normal, QIcon::Off);
    result.addPixmap(tPxm0, QIcon::Normal,      QIcon::Off);
    result.addPixmap(tPxm0, QIcon::Active,      QIcon::Off);
    result.addPixmap(tPxm0, QIcon::Disabled,    QIcon::Off);
    result.addPixmap(tPxm0, QIcon::Selected,    QIcon::Off);
    result.addPixmap(tPxm0, QIcon::Normal,      QIcon::On);
    result.addPixmap(tPxm0, QIcon::Active,      QIcon::On);
    result.addPixmap(tPxm0, QIcon::Disabled,    QIcon::On);
    result.addPixmap(tPxm0, QIcon::Selected,    QIcon::On);
    return mIcon = result;
}

QPixmap ToolButton::generate(const QIcon::Mode aMode, const QIcon::State aState)
{
    QPixmap result(mSize);
    const QColor cButtonColor = mBaseColor;
    const QColor cTextColor(Qt::black);
    const SCRect cOuterRect(result.rect());
    const SCRect cTextRect = cOuterRect.scaled(0.75);
    result.fill(cButtonColor);
#if 1
    QPainter tPainter(&result);
    tPainter.fillRect(cOuterRect(), cButtonColor);
    tPainter.setFont(QFont("typewriter", 12));
    tPainter.setPen(QPen(cTextColor));
    tPainter.drawText(cTextRect(), mText);
    tPainter.end();
#endif
    return result;
}

#if 0
void ToolButton::paintEvent(QPaintEvent *event)
{
    QRect tFullRect = event->rect();
    QPainter tPainter(this);
    tPainter.fillRect(tFullRect, mBaseColor());
    tPainter.end();
}
#endif
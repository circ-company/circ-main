#include "ToolButton.h"

#include <QFont>
#include <QPainter>
#include <QPaintEvent>

#include <Log.h>
#include <SCRect.h>


ToolButton::ToolButton(const UText aText, const UText aColorName,
                       QWidget *parent)
    : QToolButton(parent)
    , cmButtonSize(baseSize())
    , mText(aText)
    , mBaseColor(aColorName)
{
    setText(aText);
    setFixedSize(cmButtonSize);
    setToolButtonStyle(Qt::ToolButtonTextOnly);
}

QPixmap ToolButton::flat() const
{
    FNENTER();
    QPixmap result = generatePixmapFor(QIcon::Disabled, QIcon::On);
    FNRTNVALUE(result, "QPixmap");
    return result;
}

QIcon ToolButton::makeIcon()
{
    FNENTER();
    QIcon result;
    QPixmap tPxm0 = generatePixmapFor(QIcon::Normal,     QIcon::Off);
    result.addPixmap(tPxm0, QIcon::Normal,      QIcon::Off);
    result.addPixmap(tPxm0, QIcon::Active,      QIcon::Off);
    result.addPixmap(tPxm0, QIcon::Disabled,    QIcon::Off);
    result.addPixmap(tPxm0, QIcon::Selected,    QIcon::Off);
    result.addPixmap(tPxm0, QIcon::Normal,      QIcon::On);
    result.addPixmap(tPxm0, QIcon::Active,      QIcon::On);
    result.addPixmap(tPxm0, QIcon::Disabled,    QIcon::On);
    result.addPixmap(tPxm0, QIcon::Selected,    QIcon::On);
    FNRTNVALUE(result, "QIcon");
    return mIcon = result;
}

QPixmap ToolButton::generatePixmapFor(const QIcon::Mode aMode,
                             const QIcon::State aState) const
{
    FNENTER();
    FNARG(aMode, "QIcon::Mode");
    FNARG(aState, "QIcon::State");
    QPixmap result(cmButtonSize);
    const Color cButtonColor = mBaseColor.darkerK(200);
    const Color cTextColor(Qt::black);
    const SCRect cOuterRect(result.rect());
    result.fill(cButtonColor());
#if 0

9286
    const SCRect cTextRect = cOuterRect.scaled(0.75);
    QPainter tPainter(&result);
    tPainter.fillRect(cOuterRect(), cButtonColor());
    tPainter.setFont(QFont("typewriter", 12));
    tPainter.setPen(QPen(cTextColor()));
    tPainter.drawText(cTextRect(), mText);
    tPainter.end();
#endif
    WANTDO(); Q_UNUSED(aMode); Q_UNUSED(aState);
    FNRTNVALUE(result, "QPixmap");
    return result;
}

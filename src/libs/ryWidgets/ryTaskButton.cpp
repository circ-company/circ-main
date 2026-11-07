#include "ryTaskButton.h"

#include <QPainter>
#include <QPixmap>
#include <QStaticText>
#include <QTransform>

#include <Label.h>
#include <Log.h>
#include <SCRect.h>

#include "ryTaskBar.h"

ryTaskButton::ryTaskButton(ryTaskBar *parent)
    : QToolButton{parent}
    , mpBar(parent)
{
    FNENTER();
    setObjectName("ryTaskButton:null");
}

ryTaskButton::ryTaskButton(const QString &aText, const Color aBaseColor, ryTaskBar *parent)
    : QToolButton(parent)
    , mpBar(parent)
    , mText(aText)
    , mBaseColor(aBaseColor)
{
    FNENTER();
    setObjectName("ryTaskButton:" + aText);
    mStates.setFlag(Radio);
}

Color ryTaskButton::mainColor()
{
    Color result = baseColor();
    if ( ! mStates.testFlag(Enabled))
        result = result.greyerK(450);
    return result;
}

Color ryTaskButton::borderColor()
{
    Color result = baseColor();
    if ( ! mStates.testFlag(Enabled))
        result = result.greyerK(350);
    return result;

}

Color ryTaskButton::textColor()
{
    Color result = baseColor().inverted();
    if ( ! mStates.testFlag(Enabled))
        result = result.greyerK(250);
    return result;

}

void ryTaskButton::paintEvent(QPaintEvent *event)
{
    FNENTER();
    Q_UNUSED(event);
    SCRect tOuterRect = bar()->buttonSize();
    tOuterRect.reverseSize();
    SCRect tInnerRect = tOuterRect;
    tInnerRect.scale(0.75);
    QTransform tXF;
    tXF.rotate(-90);
    const QFont cFont("Helvetica", 14, 63);

    const Color cMainColor = mainColor();
    const Color cBorderColor = borderColor();
    const Color cTextColor = textColor();

    QPainter tPainter(this);
    tPainter.fillRect(rect(), cBorderColor());
    tPainter.fillRect(tInnerRect.toQRect(), cMainColor());
    tPainter.setBrush(cTextColor());
    tPainter.setFont(cFont);
    tPainter.drawText(tInnerRect.topLeft()(), mText);
    tPainter.rotate(-90);
    tPainter.end();
    EXPECTEQ(size(), bar()->buttonSize());
    resize(bar()->buttonSize());
}

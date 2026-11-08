#include "ryTaskButton.h"

#include <QPainter>
#include <QPixmap>
#include <QStaticText>
#include <QTransform>

#include <Label.h>
#include <Log.h>
#include <SCRect.h>
#include <ObjectHelper.h>

#include "ryTaskBar.h"

ryTaskButton::ryTaskButton(ryTaskBar *parent)
    : QToolButton{parent}
    , mpBar(parent)
{
    FNENTER();
    setObjectName("ryTaskButton:null");
}

ryTaskButton::ryTaskButton(const Task aTask, const Color aBaseColor, ryTaskBar *parent)
    : QToolButton(parent)
    , mpBar(parent)
    , mpAction(new QAction(this))
    , mState($nullState)
    , mBaseColor(aBaseColor)
{
    FNENTER();
    ObjectHelper tOH(this);
    mName = tOH.enumKey("Task", aTask);
    setObjectName("ryTaskButton:" + name()());
    setUserText(name()());
    EXPECTEQ(Color::ORGB, aBaseColor.representation());
    EXPECTEQ(Color::ORGB, mBaseColor.representation());
}

Color ryTaskButton::baseColor() const
{
    EXPECTEQ(Color::ORGB, mBaseColor.representation());
    return mBaseColor;
}

Color ryTaskButton::mainColor() const
{
    Color result = baseColor();
    EXPECTEQ(Color::ORGB, result.representation());
    if (isDisabled())
        result = result.greyerK(100);
    return result;
}

Color ryTaskButton::borderColor() const
{
    Color result = baseColor();
    EXPECTEQ(Color::ORGB, result.representation());
    if (isDisabled())
        result = result.greyerK(200);
    return result;
}

Color ryTaskButton::textColor() const
{
    Color result = baseColor().inverted();
    EXPECTEQ(Color::ORGB, result.representation());
    if (isDisabled())
        result = result.greyerK(50);
    return result;
}

void ryTaskButton::setUserText(const QString aEnglishText)
{
    tr(qPrintable(aEnglishText), "TaskButton");
}

void ryTaskButton::paintEvent(QPaintEvent *event)
{
    FNENTER();
    Q_UNUSED(event);
    DUMPVAR(mBaseColor.representation());
    if (mBaseColor.isNull()) return;                           /*/=====\*/
    EXPECTEQ(Color::ORGB, baseColor().representation());
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
    tPainter.drawText(tInnerRect.topLeft()(), mUserText);
    tPainter.rotate(-90);
    tPainter.end();
    EXPECTEQ(size(), bar()->buttonSize());
    resize(bar()->buttonSize());
}

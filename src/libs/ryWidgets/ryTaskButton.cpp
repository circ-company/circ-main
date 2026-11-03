#include "ryTaskButton.h"

#include <QPainter>
#include <QPixmap>

#include <Log.h>

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

void ryTaskButton::paintEvent(QPaintEvent *event)
{
    FNENTER();
    Q_UNUSED(event);
    QPainter tPainter(this);
    resize(bar()->buttonSize());
    tPainter.fillRect(rect(), mBaseColor());
    tPainter.end();
}

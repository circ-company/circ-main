#include "BlankPage.h"

#include <QColor>
#include <QPainter>
#include <QPaintEvent>

#include <Button.h>
#include <Color.h>
#include <Label.h>
#include <Log.h>
#include <SCRect.h>

BlankPage::BlankPage(LoyaltyDisplayScreen *parent)
    : BaseLoyaltyDisplayPage(LoyaltyDisplayScreen::Blank, parent) {;}

BlankPage::~BlankPage() {;}

void BlankPage::setup()
{
    FNENTER();
    resize(size());
    mPaintModes = Background;
    repaint();

    setLayout(gridLayout());
    setupButtonBar();
    show();
    FNRTNVOID();
}

void BlankPage::paintEvent(QPaintEvent *event)
{
    FNENTER();
    if (mPaintModes & Background)
    {
        QPainter tPainter(this);
        tPainter.fillRect(event->rect(), QColor("papayawhip"));
        tPainter.end();
    }
    FNRTNVOID();
}

void BlankPage::setupButtonBar()
{
    FNENTER();
    QList<Qt::GlobalColor> tButtonColors;
    tButtonColors << Qt::red << Qt::yellow << Qt::green << Qt::cyan
                  << Qt::blue << Qt::magenta << Qt::lightGray
                  << Qt::darkRed << Qt::darkGreen
                  << Qt::darkBlue << Qt::darkMagenta << Qt::darkGray;
    Index rowIx = 0, colIx = 0;
    DUMPVAR(gridLayout()->objectName());
    foreach (const Qt::GlobalColor cQGC, tButtonColors)
    {
        Color tColor(cQGC);
        Key tColorKey = "Button/" + tColor.name();
        Button tButton(Size(96, 64), tColor);
        QLabel * pLabel = new QLabel(tColorKey(), this);
        NEWOBJ(pLabel, "QLabel", this);
        pLabel->setPixmap(tButton.flat());
        gridLayout()->addWidget(pLabel, rowIx, colIx++);
        DUMPVAR(pLabel->text());
    }
    show();
    FNRTNVOID();
}

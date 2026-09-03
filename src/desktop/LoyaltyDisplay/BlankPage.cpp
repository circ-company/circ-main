#include "BlankPage.h"

#include <QColor>
#include <QPainter>
#include <QPaintEvent>

#include <ToolButton.h>
#include <Color.h>
#include <Label.h>
#include <Log.h>
#include <SCRect.h>

#include "NormalFaceLayoutWidget.h"


BlankPage::BlankPage(LoyaltyDisplayScreen *parent)
    : BaseLoyaltyDisplayPage(LoyaltyDisplayScreen::Home, parent)
{
    setObjectName("HomePage:BaseLoyaltyDisplayPage");
}

BlankPage::~BlankPage() {;}

void BlankPage::setup()
{
    FNENTER();
    resize(size());
    mPaintModes = Background;
    repaint();
    for (Index iy = 0; iy < scmGridSize.width(); ++iy)
    {
        for (Index ix = 0; ix < scmGridSize.height(); ++ix)
        {
            QWidgetItem * pPlaceholder
                = new NormalFaceLayoutWidget(Point(int(ix), int(iy)),
                                             parentWidget());
            grid()->addItem(pPlaceholder, ix, iy,
                            Qt::AlignCenter);
        }
    }
    setLayout(grid());
    show();
    FNRTNVOID();
}

void BlankPage::add(const Index aRow, const QImage aImage)
{

}

KeySeg BlankPage::key() const
{
    return KeySeg("Blank");
}

QString BlankPage::name() const
{
    return (tr("Blank", "pagename"));
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


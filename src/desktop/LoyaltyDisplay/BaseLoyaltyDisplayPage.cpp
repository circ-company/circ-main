#include "BaseLoyaltyDisplayPage.h"

#include <QPainter>
#include <QPaintEvent>

#include <Log.h>

#include "LoyaltyDisplayScreen.h"
#include "NormalFaceLayoutWidget.h"

const Size BaseLoyaltyDisplayPage::scmGridSize = Size(8, 4);

BaseLoyaltyDisplayPage::BaseLoyaltyDisplayPage(const LoyaltyDisplayScreen::PageType aType,
                                               LoyaltyDisplayScreen *parent)
    : QWidget{parent}
    , cmType(aType)
{
    setObjectName("BaseLoyaltyDisplayPage:" + LoyaltyDisplayScreen::key(cmType)());
    mRowImageCounts.fill(0, scmGridSize.height());
}

BaseLoyaltyDisplayPage::~BaseLoyaltyDisplayPage()
{
}

void BaseLoyaltyDisplayPage::initialize()
{
    FNENTER();
    mpGridLayout = new QGridLayout(this);
    NEWOBJ(mpGridLayout, "QGridLayout", this);
    mpGridLayout->setObjectName("BaseLoyaltyDisplayPage:QGridLayout");
    FNRTNVOID();
    CKPOINTER(mpGridLayout);
}

void BaseLoyaltyDisplayPage::setup()
{
    FNENTER();
    resize(size());
    setLayout(grid());
    mPaintModes = Background;
    repaint();
    update();
    show();
    for (Index iy = 0; iy < scmGridSize.width(); ++iy)
        for (Index ix = 0; ix < scmGridSize.height(); ++ix)
        {
            QWidgetItem * pPlaceholder
                = new NormalFaceLayoutWidget(parentWidget());
            grid()->addItem(pPlaceholder, ix, iy, Qt::AlignCenter);
            show();
        }
    FNRTNVOID();
}

KeySeg BaseLoyaltyDisplayPage::key() const
{
    return LoyaltyDisplayScreen::key(cmType);
}

LoyaltyDisplayScreen * BaseLoyaltyDisplayPage::screen() const
{
    CKPOINTER(parent());
    return qobject_cast<LoyaltyDisplayScreen *>(parent());
}

QGridLayout * BaseLoyaltyDisplayPage::grid()
{
    return qobject_cast<QGridLayout *>(mpGridLayout);
}

void BaseLoyaltyDisplayPage::paintEvent(QPaintEvent *event)
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

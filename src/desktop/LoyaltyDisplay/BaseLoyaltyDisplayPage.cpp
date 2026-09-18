#include "BaseLoyaltyDisplayPage.h"

#include <QPainter>
#include <QPaintEvent>

#include <Log.h>

#include "FileImageSource.h"
#include "LoyaltyDisplayScreen.h"
#include "NormalFaceLayoutWidget.h"

const Size BaseLoyaltyDisplayPage::scmGridSize = Size(8, 4);

BaseLoyaltyDisplayPage::BaseLoyaltyDisplayPage(const EightCC aECC,
                                    LoyaltyDisplayScreen *parent)
    : QWidget{parent}
    , cmECC(aECC)
{
    setObjectName("BaseLoyaltyDisplayPage:" + cmECC);
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
    DUMPVAR(size());
    DUMPVAR(scmGridSize);
    DUMPVAR(screen()->faceSize());
    resize(size());
    setBackgroundRole(QPalette::ColorRole::Base);
    for (Index iy = 0; iy < scmGridSize.width(); ++iy)
    {
        grid()->setColumnMinimumWidth(iy, screen()->faceSize().width());
        for (Index ix = 0; ix < scmGridSize.height(); ++ix)
            grid()->setRowMinimumHeight(ix, screen()->faceSize().height());
    }
    setLayout(grid());
    FNRTNVOID();
}

void BaseLoyaltyDisplayPage::add(const Index ix,
                                 NormalFaceLayoutWidget *pFaceItem)
{
    FNENTER();
    FNARG(ix, "Index");
    CKPOINTER(pFaceItem);
    FNARG(pFaceItem->key()(), "QString");
    const Size cLayoutSize = screen()->faceLayout();
    DUMPVAR(cLayoutSize);
    const Point cIndexPoint(cLayoutSize, ix);
    DUMPVAR(cIndexPoint());
    Point tModuloPoint = cIndexPoint;
    tModuloPoint %= Size(cLayoutSize);
    DUMPVAR(tModuloPoint());
    if (0 == cIndexPoint.col())
        clearRow(tModuloPoint.y());
    pFaceItem->point(cIndexPoint);
    grid()->addItem(pFaceItem, tModuloPoint.row(), tModuloPoint.col());
    FNRTNVOID();
}

QString BaseLoyaltyDisplayPage::name() const
{
    return screen()->tbGen()->name(ecc());
}

void BaseLoyaltyDisplayPage::clearRow(const Index aRow)
{
    Size tLayoutSize = screen()->faceLayout();
    Index tRow = aRow % tLayoutSize.height();
    NormalFaceLayoutWidget * pItem = new NormalFaceLayoutWidget(screen());
    for (Index ixCol = 0; ixCol < tLayoutSize.width(); ++ixCol)
    {
        Point tPoint((int(tRow)), int(ixCol));
        pItem->point(tPoint);
        grid()->addItem(pItem, tPoint.row(), tPoint.col());
    }
}

LoyaltyDisplayScreen * BaseLoyaltyDisplayPage::screen() const
{
    CKPOINTER(parent());
    return qobject_cast<LoyaltyDisplayScreen *>(parent());
}

QGridLayout * BaseLoyaltyDisplayPage::grid()
{
    CKPOINTER(mpGridLayout);
    return qobject_cast<QGridLayout *>(mpGridLayout);
}


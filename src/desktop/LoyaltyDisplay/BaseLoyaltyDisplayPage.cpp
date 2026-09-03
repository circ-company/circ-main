#include "BaseLoyaltyDisplayPage.h"

#include <Log.h>

#include "LoyaltyDisplayScreen.h"

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

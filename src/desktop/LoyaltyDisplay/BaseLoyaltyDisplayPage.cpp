#include "BaseLoyaltyDisplayPage.h"

#include <Log.h>

#include "LoyaltyDisplayScreen.h"

BaseLoyaltyDisplayPage::BaseLoyaltyDisplayPage(const LoyaltyDisplayScreen::PageType aType,
                                               LoyaltyDisplayScreen *parent)
    : QWidget{parent}
    , cmType(aType)
    , mKeyLabelMap(this)
{
    setObjectName("BaseLoyaltyDisplayPage:" + key()());
}

BaseLoyaltyDisplayPage::~BaseLoyaltyDisplayPage()
{
    mKeyLabelMap.releaseAll();
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

QGridLayout * BaseLoyaltyDisplayPage::gridLayout()
{
    return qobject_cast<QGridLayout *>(mpGridLayout);
}

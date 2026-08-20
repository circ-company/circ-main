#include "BaseLoyaltyDisplayPage.h"

#include <Log.h>

#include "LoyaltyDisplayScreen.h"

BaseLoyaltyDisplayPage::BaseLoyaltyDisplayPage(const Key aKey,
                                    LoyaltyDisplayScreen *parent)
    : QWidget{parent}
    , cmKey(aKey)
{
    setObjectName("BaseLoyaltyDisplayPage:" + key()());
}

void BaseLoyaltyDisplayPage::screenSize(const Size aSz)
{
    resize(aSz);
    updateGeometry();
    update();
}

LoyaltyDisplayScreen *BaseLoyaltyDisplayPage::screen() { CKPOINTER(parent()); return qobject_cast<LoyaltyDisplayScreen *>(parent()); }

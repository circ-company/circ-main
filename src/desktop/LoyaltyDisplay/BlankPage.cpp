#include "BlankPage.h"

#include <QColor>

#include <ToolButton.h>
#include <Color.h>
#include <Label.h>
#include <Log.h>
#include <SCRect.h>

BlankPage::BlankPage(LoyaltyDisplayScreen *parent)
    : BaseLoyaltyDisplayPage(LoyaltyDisplayScreen::Home, parent)
{
    setObjectName("HomePage:BaseLoyaltyDisplayPage");
}

BlankPage::~BlankPage() {;}

void BlankPage::setup()
{
    FNENTER();
    BaseLoyaltyDisplayPage::setup();

    // do stuff here

    show();
    FNEMIT("setupd");
    emit setupd();
    FNRTNVOID();
}

KeySeg BlankPage::key() const
{
    return KeySeg("Blank");
}

QString BlankPage::name() const
{
    return (tr("Blank", "pagename"));
}



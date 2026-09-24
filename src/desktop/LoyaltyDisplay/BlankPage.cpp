#include "BlankPage.h"

#include <QColor>

#include <ToolButton.h>
#include <Color.h>
#include <Label.h>
#include <Log.h>
#include <SCRect.h>

#include "NormalFaceLayoutWidget.h"

BlankPage::BlankPage(LoyaltyDisplayScreen *parent)
    : BaseLoyaltyDisplayPage(EightCC("Home"), parent)
{
    setObjectName("HomePage:BaseLoyaltyDisplayPage");
}

BlankPage::~BlankPage() {;}

void BlankPage::setup()
{
    FNENTER();
    BaseLoyaltyDisplayPage::setup();

    // do stuff here
    for (Index iy = 0; iy < scmGridSize.width(); ++iy)
    {
        for (Index ix = 0; ix < scmGridSize.height(); ++ix)
        {
            QWidgetItem * pPlaceholder
                = new NormalFaceLayoutWidget(screen());
            grid()->addItem(pPlaceholder, ix, iy, Qt::AlignCenter);
        }
    }

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



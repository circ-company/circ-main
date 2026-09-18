#include "LoyaltyDisplayScreen.h"

#include <QColor>
#include <QMetaEnum>
#include <QStackedLayout>
#include <QToolBar>
#include <QThread>
#include <QWidget>

#include <Color.h>
#include <EnumHelper.h>
#include <Label.h>
#include <Log.h>
#include <ToolButton.h>

#include "BaseLoyaltyDisplayPage.h"
#include "BlankPage.h"
#include "LoyaltyDisplayBackend.h"

LoyaltyDisplayScreen::LoyaltyDisplayScreen(LoyaltyDisplayBackend *parent)
    : QMainWindow(nullptr)
    , mpBackend(parent)
{
    setObjectName("LoyaltyDisplayScreen");
}

LoyaltyDisplayScreen::~LoyaltyDisplayScreen()
{
    ;
}

// ======================== slots ========================

void LoyaltyDisplayScreen::start()
{
    FNENTER();
    WANTDO("Anything?");
    FNEMIT("started");
    emit started();
    FNRTNVOID();
}

void LoyaltyDisplayScreen::initialize()
{
    FNENTER();

    mpMainWidget = new QWidget(this);
    NEWOBJ(mpMainWidget, "QWidget", this);
    mpPageStack = new QStackedLayout();
    NEWOBJ(mpPageStack, "QStackedLayout", this);
    mpButtonGenerator = new ToolButtonGenerator();
    NEWOBJ(mpButtonGenerator, "ToolButtonGenerator", this);

    tbGen()->initialize();

    FNEMIT("initialized");
    emit initialized();
    FNRTNVOID();
}

void LoyaltyDisplayScreen::setup()
{
    FNENTER();
    CKPOINTER(mpMainWidget);
    CKPOINTER(mpPageStack);
    screenSize(baseScreenSize());
    setFixedSize(screenSize());
    mpToolBar = addToolBar("Main");
    NEWOBJ(mpToolBar, "QToolBar", this);
    addButtons();

    mpMainWidget->setLayout(mpPageStack);
    setCentralWidget(mpMainWidget);

    addPage(new BlankPage(this)); // dummy page, Type=$null


    FNEMIT("setupd");
    emit setupd();
}

void LoyaltyDisplayScreen::run()
{
    FNENTER();

    // TODO Move Backend to it's thread
    WANTDO("Move Backend to it's thread");

    emit running();
    FNRTNVOID();
}

// ======================== end slots ========================

void LoyaltyDisplayScreen::screenSize(const Size aSz)
{
    FNENTER();
    FNARG(aSz, "Size");
    mScreenSize = aSz;
    DUMPVAR(mScreenSize);
    CKPOINTER(mpMainWidget);
    mpMainWidget->setFixedSize(mScreenSize);
    setFixedSize(mScreenSize);
    mpMainWidget->resize(mScreenSize);
    updateGeometry();
    mpMainWidget->updateGeometry();
    FNRTNVOID();
}

void LoyaltyDisplayScreen::addPage(BaseLoyaltyDisplayPage *pPage)
{
    pPage->start();
    pPage->initialize();
    pPage->setup();
    ASSERT(connect(backend(), &LoyaltyDisplayBackend::addFace,
                   pPage, &BaseLoyaltyDisplayPage::add));
    mEccPageMap.insert(pPage->ecc(), pPage);
    mpPageStack->addWidget(pPage);
}

Size LoyaltyDisplayScreen::buttonSize()
{
    return Size(96, 64);
}

Size LoyaltyDisplayScreen::buttonLayout()
{
    return Size(12, 1);
}

Size LoyaltyDisplayScreen::faceSize()
{
    return Size(160);
}

Size LoyaltyDisplayScreen::faceLayout()
{
    return Size(8, 5);

}

LoyaltyDisplayBackend *LoyaltyDisplayScreen::backend()
{
    CKPOINTER(mpBackend); return mpBackend;
}

void LoyaltyDisplayScreen::addButtons()
{
    for (Index ix = 0; ix < Index(tbGen()->buttonCount()); ++ix)
    {
        const EightCC cECC = tbGen()->ecc(ix);
        ToolButton * pButton = tbGen()->button(cECC);
        mpToolBar->addWidget(pButton);
    }
}


ToolButtonGenerator *LoyaltyDisplayScreen::tbGen()
{
    CKPOINTER(mpButtonGenerator);
    return mpButtonGenerator;
}

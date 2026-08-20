#include "LoyaltyDisplayScreen.h"

#include <QTabWidget>
#include <QThread>

#include <Log.h>

#include "BaseLoyaltyDisplayPage.h"

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

void LoyaltyDisplayScreen::start()
{
    FNENTER();

    FNEMIT("started");
    emit started();
    FNRTNVOID();
}

void LoyaltyDisplayScreen::initialize()
{
    FNENTER();
    mpMainWidget = new QTabWidget(this);
    NEWOBJ(mpMainWidget, "QTabWidget", this);
    FNEMIT("initialized");
    emit initialized();
    FNRTNVOID();
}

void LoyaltyDisplayScreen::setup()
{
    FNENTER();
    screenSize(baseScreenSize());

    CKPOINTER(mpMainWidget);
    setCentralWidget(mpMainWidget);

    FNEMIT("setupd");
    emit setupd();
}

void LoyaltyDisplayScreen::run()
{
    FNENTER();

    // TODO Move Backend to it's thread
    NEEDDO("Move Backend to it's thread");

    mIsRunning = true;
    FNEMIT("running");
    emit running();
    FNRTNVOID();
}

void LoyaltyDisplayScreen::screenSize(const Size aSz)
{
    FNENTER();
    FNARG(aSz, "Size");
    mScreenSize = aSz;
    DUMPVAR(mScreenSize);
    //qDebug() << Q_FUNC_INFO << mScreenSize;
    CKPOINTER(mpMainWidget);
    mpMainWidget->setFixedSize(mScreenSize);
    setFixedSize(mScreenSize);
    mpMainWidget->resize(mScreenSize);
    updateGeometry();
    mpMainWidget->updateGeometry();
    foreach (BaseLoyaltyDisplayPage * pPage, mKeyPageMap.values())
        pPage->screenSize(mScreenSize);
    FNRTNVOID();
}

LoyaltyDisplayBackend *LoyaltyDisplayScreen::backend()
{
    CKPOINTER(mpBackend); return mpBackend;
}


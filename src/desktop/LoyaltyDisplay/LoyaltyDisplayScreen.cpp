#include "LoyaltyDisplayScreen.h"

#include <QMetaEnum>
#include <QTabWidget>
#include <QThread>

#include <EnumHelper.h>
#include <Log.h>

#include "BaseLoyaltyDisplayPage.h"
#include "BlankPage.h"

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
    addPage(new BlankPage(this));

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
    FNRTNVOID();
}

void LoyaltyDisplayScreen::addPage(BaseLoyaltyDisplayPage *pPage)
{
    pPage->initialize();
    pPage->setup();
    mKeyPageMap.insert(pPage->key(), pPage);
    mpMainWidget->addTab(pPage, QIcon(), pPage->key()());
    mpMainWidget->setCurrentWidget(pPage);
}

KeySeg LoyaltyDisplayScreen::key(const PageType aType)
{
    QMetaEnum tMetaEnum = QMetaEnum::fromType<PageType>();
    const char* pchKey = tMetaEnum.valueToKey(aType);
    const CText cText(pchKey);
    return KeySeg(cText);
}

LoyaltyDisplayBackend *LoyaltyDisplayScreen::backend()
{
    CKPOINTER(mpBackend); return mpBackend;
}


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

    mpMainWidget = new QWidget(this);
    NEWOBJ(mpMainWidget, "QWidget", this);
    mpMainStack = new QStackedLayout();
    NEWOBJ(mpMainStack, "QStackedLayout", this);
    mpToolBar = new QToolBar(this);
    NEWOBJ(mpToolBar, "QToolBar", this);

    FNEMIT("initialized");
    emit initialized();
    FNRTNVOID();
}

void LoyaltyDisplayScreen::setup()
{
    FNENTER();
    screenSize(baseScreenSize());
    setFixedSize(screenSize());

    mpToolBar = addToolBar(tr("Main", "toolbar"));
    CKPOINTER(mpToolBar);
    setupButtonBar();

    mpMainWidget->setLayout(mpMainStack);
    setCentralWidget(mpMainWidget);

    addPage(new BlankPage(this));

    FNEMIT("setupd");
    emit setupd();
}

void LoyaltyDisplayScreen::run()
{
    FNENTER();

    // TODO Move Backend to it's thread
    NEEDDO("Move Backend to it's thread");

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
    mpMainStack->addWidget(pPage);
    setCentralWidget(pPage);
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

void LoyaltyDisplayScreen::setupButtonBar()
{
    FNENTER();
    QList<Qt::GlobalColor> tButtonColors;
    tButtonColors << Qt::red << Qt::yellow << Qt::green
                  << Qt::cyan << Qt::blue << Qt::magenta
                  << Qt::lightGray << Qt::darkRed << Qt::darkGreen
                  << Qt::darkBlue << Qt::darkMagenta << Qt::darkGray;
    DUMPVAR(tButtonColors.count());
    DUMPVAR(PageType::$Count);
    EXPECTEQ(tButtonColors.count(), PageType::$Count);
    for (Index ix = 0; ix < PageType::$Count; ++ix)
    {
        QColor tColor = tButtonColors.value(ix);
        Key tColorKey = "Button/" + tColor.name();
        UText tText = EnumHelper::name<PageType>(PageType(ix));
        ToolButton * pButton = new ToolButton(tText, tColor, Size(96, 64), this);
        mpToolBar->addWidget(pButton);
    }
    show();
    FNRTNVOID();
}

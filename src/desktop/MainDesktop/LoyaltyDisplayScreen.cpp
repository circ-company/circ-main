#include "LoyaltyDisplayScreen.h"

#include "Log.h"

LoyaltyDisplayScreen::LoyaltyDisplayScreen(QQApplication *app)
    : QQMainWindow(QQMainWindow::ImageLabel, app)
{
    setObjectName("MainWindow");
}

void LoyaltyDisplayScreen::run()
{
    FNENTER();
    QQMainWindow::run();
    connect(this, &QQMainWindow::running, this, &QQMainWindow::initialize);
    connect(this, &QQMainWindow::initialized, this, &QQMainWindow::setup);
    connect(this, &QQMainWindow::setuped, this, &QQMainWindow::ready);
    FNEMIT(running());
    emit running();
    FNRTNVOID();
}

void LoyaltyDisplayScreen::initialize()
{
    FNENTER();
    QQMainWindow::initialize();
    FNEMIT(initialized());
    emit initialized();
    FNRTNVOID();
}

void LoyaltyDisplayScreen::setup()
{
    FNENTER();
    QQMainWindow::setup();
    show();
    FNEMIT(setuped());
    emit setuped();
    FNRTNVOID();
}

void LoyaltyDisplayScreen::ready()
{
    FNENTER();
    QQMainWindow::ready();
    FNEMIT(readied());
    emit readied();
    FNRTNVOID();
}


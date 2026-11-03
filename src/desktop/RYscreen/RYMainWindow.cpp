#include "RYMainWindow.h"

#include <QTimer>
#include <QHBoxLayout>

#include <Log.h>

#include <ryFaceGrid.h>
#include <ryTaskBar.h>

#include "RYApplication.h"

RYMainWindow::RYMainWindow(RYApplication *parent)
    : QMainWindow(nullptr)
    , mpApplication(parent)
{
    FNENTER();
    setObjectName("RYMainWindow");
    resize(screenSize());
    connect(this, &RYMainWindow::running, this, &RYMainWindow::initialize);
    connect(this, &RYMainWindow::initialized, this, &RYMainWindow::setup);
    connect(this, &RYMainWindow::setuped, this, &RYMainWindow::ready);
    QTimer::singleShot(10, this, &RYMainWindow::run);
}

RYMainWindow::~RYMainWindow()
{
    FNENTER();
}

void RYMainWindow::run()
{
    FNENTER();
    emit running();
}

void RYMainWindow::initialize()
{
    FNENTER();
    mpMainWidget = new QWidget(this);
    mpBoxLayout = new QHBoxLayout;
    mpTaskBar = new ryTaskBar(this);
    mpFaceGrid = new ryFaceGrid(this);
    Q_CHECK_PTR(mpMainWidget);
    Q_CHECK_PTR(mpBoxLayout);
    Q_CHECK_PTR(mpTaskBar);
    Q_CHECK_PTR(mpFaceGrid);
    taskBar()->initialize();
    emit initialized();
}

void RYMainWindow::setup()
{
    FNENTER();
    taskBar()->setup();
    layout()->addWidget(taskBar());
    layout()->addLayout(faceGrid());
    Q_CHECK_PTR(mpMainWidget);
    mpMainWidget->setLayout(layout());
    setCentralWidget(mpMainWidget);
    showNormal();
    emit setuped();
}

void RYMainWindow::ready()
{
    FNENTER();
    emit readied();
}

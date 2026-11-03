#include "ryTaskBar.h"

#include <QVBoxLayout>

#include <Log.h>
#include <ObjectHelper.h>

ryTaskBar::ryTaskBar(QWidget *parent)
    : QWidget(parent)
{
    FNENTER();
    setObjectName("ryToolBar");
}

void ryTaskBar::initialize()
{
    FNENTER();
    mpLayout = new QVBoxLayout;
    Q_CHECK_PTR(mpLayout);
    emit initialized();
}

void ryTaskBar::setup()
{
    FNENTER();
    ObjectHelper tOH(this);
    ryTaskButton * pBtnGather = new ryTaskButton("Gather", Qt::blue, this);
    ryTaskButton * pBtnQuery  = new ryTaskButton("Query", Qt::darkBlue, this);
    ryTaskButton * pBtnEnroll = new ryTaskButton("Enroll", Qt::cyan, this);
    ryTaskButton * pBtnReward = new ryTaskButton("Reward", Qt::darkYellow, this);
    ryTaskButton * pBtnAlert  = new ryTaskButton("Alert", Qt::red, this);
    ryTaskButton * pBtnMaint  = new ryTaskButton("Maint", Qt::gray, this);
    Q_CHECK_PTR(pBtnGather);
    Q_CHECK_PTR(pBtnQuery);
    Q_CHECK_PTR(pBtnEnroll);
    Q_CHECK_PTR(pBtnReward);
    Q_CHECK_PTR(pBtnAlert);
    Q_CHECK_PTR(pBtnMaint);
    Q_CHECK_PTR(mpLayout);
    mpLayout->addWidget(pBtnGather);
    mpLayout->addWidget(pBtnQuery);
    mpLayout->addWidget(pBtnEnroll);
    mpLayout->addWidget(pBtnReward);
    mpLayout->addWidget(pBtnAlert);
    mpLayout->addWidget(pBtnMaint);
    setLayout(mpLayout);
    show();
    //mpButtonGroup->addButton(new ryTaskButton(tr(qPrintable(tOH.enumKey("Task", Gather)), "TaskButton"), Qt::darkBlue, this), Maint);
    emit setuped();
}

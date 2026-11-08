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
    mButtonList.reserve(ryTaskButton::$maxTask);
    emit initialized();
}

void ryTaskBar::setup()
{
    FNENTER();
    const Color::List cColors = Color::List() << Qt::blue << Qt::darkBlue
                                              << Qt::green << Qt::darkYellow
                                              << Qt::darkRed << Qt::black;
    ObjectHelper tOH(new ryTaskButton(this));
    for (int ix = ryTaskButton::$nullTask+1; ix < ryTaskButton::$maxTask; ++ix)
    {
        ryTaskButton * pButton = new ryTaskButton(ryTaskButton::Task(ix), cColors[ix], this);
        mButtonList.append(pButton);
        mpLayout->addWidget(pButton);
    }
    setLayout(mpLayout);
    show();
    emit setuped();
}

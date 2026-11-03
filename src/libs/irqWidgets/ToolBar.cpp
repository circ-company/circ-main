#include "ToolBar.h"

#include <QMainWindow>

ToolBar::ToolBar(QWidget * parent)
    : QToolBar(parent)
{
    setObjectName("ToolBar");
}

ToolBar::ToolBar(const Qt::ToolBarArea aArea, QWidget *parent)
    : QToolBar(parent)
    , mArea(aArea)
{
    setObjectName("ToolBar");
}

void ToolBar::addTo(QMainWindow *pMW)
{
    Q_CHECK_PTR(pMW);
    pMW->addToolBar(mArea, this);
}

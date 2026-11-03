#pragma once

#include <QToolBar>
#include <QWidget>

class ToolBar : public QToolBar
{
    Q_OBJECT
public:
    explicit ToolBar(QWidget * parent=nullptr);
    explicit ToolBar(const Qt::ToolBarArea, QWidget * parent=nullptr);

    void addTo(QMainWindow * pMW);

private:
    Qt::ToolBarArea mArea;
};

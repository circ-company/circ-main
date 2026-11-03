#pragma once

#include <QWidget>
#include <QWidgetAction>

class BaseWidgetAction : public QWidgetAction
{
    Q_OBJECT
protected: // ctors
    BaseWidgetAction(QObject *parent=nullptr);

protected: // pointers
    virtual QWidget *createWidget(QWidget *parent) = 0;

};

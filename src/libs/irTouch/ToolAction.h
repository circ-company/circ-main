#pragma once

#include <QAction>
#include <QObject>

class ToolAction : public QAction
{
    Q_OBJECT
public:
    explicit ToolAction(QObject *parent = nullptr);
};

#pragma once

#include <QWidget>

class MainWindow;

class BaseRYScreen : public QWidget
{
    Q_OBJECT
protected: // ctors
    explicit BaseRYScreen(MainWindow *parent);

public slots:
    void addToMain();

signals:


private:
    MainWindow * mpMainWindow=nullptr;
};

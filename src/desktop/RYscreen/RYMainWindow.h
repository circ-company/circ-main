#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class RYMainWindow;
}
QT_END_NAMESPACE

class RYMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    RYMainWindow(QWidget *parent = nullptr);
    ~RYMainWindow();

private:
    Ui::RYMainWindow *ui;
};

#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class irViewMainWindow;
}
QT_END_NAMESPACE

class irViewMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    irViewMainWindow(QWidget *parent = nullptr);
    ~irViewMainWindow();

private:
    Ui::irViewMainWindow *ui;
};

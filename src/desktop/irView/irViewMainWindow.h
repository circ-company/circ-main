#pragma once

#include <QMainWindow>


#include <QMdiArea>
#include <QStackedLayout>
#include <QWidget>
class QMenuBar;

#include <FileInfo.h>
#include <Label.h>

class irViewMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    irViewMainWindow();
    ~irViewMainWindow();

public slots:
    void run();
    void initialize();
    void setup();
    void start();

signals:
    void running();
    void initialized();
    void setuped();
    void started();

private:
    void setupMenus();

private:
    QWidget * mpMainWidget=nullptr;
    QStackedLayout * mpStack=nullptr;
    bool mMdiMode=false;
    QMdiArea * mpMdiArea=nullptr;
    Label * mpMainLabel=nullptr;
//    QMenuBar * mpMainMenuBar=nullptr;
};

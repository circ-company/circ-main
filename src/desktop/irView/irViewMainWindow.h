#pragma once

#include <QMainWindow>

#include <QFileDialog>
#include <QMdiArea>
#include <QStackedLayout>
#include <QWidget>

#include <FileInfo.h>
#include <Label.h>
#include <Log.h>

class irViewApplication;

class irViewMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    irViewMainWindow(irViewApplication * pApp);
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

public: // non-const
    FileInfo doFileOpenDialog();

public: // pointers
    irViewApplication * app();

private:
    void setupMenus();

private:
    irViewApplication * mpApplication;
    QWidget * mpMainWidget=nullptr;
    QStackedLayout * mpStack=nullptr;
    bool mMdiMode=false;
    QMdiArea * mpMdiArea=nullptr;
    Label * mpMainLabel=nullptr;
    QFileDialog * mpFileDialog=nullptr;
    QFileDialog * mpDirDialog=nullptr;
};

inline irViewApplication *irViewMainWindow::app() { MASSERT(mpApplication); return mpApplication; }

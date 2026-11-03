#pragma once

#include <QMainWindow>

#include <QFlags>
#include <QWidget>
class QStackedLayout;
class QGridLayout;

class Application;
class Size;

#include "Label.h"
#include "QQTextDocument.h"
#include "QQTextEdit.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public: // types
    enum Content
    {
        $null               = 0,
        Grid                = 0x00000001,
        Stack               = 0x00000002,
        TextEdit            = 0x00000100,
        TextDocument        = 0x00000200,
        ImageLabel          = 0x00000800,
        LogStderr           = 0x00010000,
        StatusBar           = 0x01000000,
        ReadOnly            = 0x80000000,
    };
    Q_DECLARE_FLAGS(Contents, Content);
    Q_FLAG(Contents);

public: // ctors
    explicit MainWindow(const Contents cf, Application *app);

public slots:
    virtual void run();
    virtual void initialize();
    virtual void setup();
    virtual void ready();
    virtual void add(QWidget * page) {;} // adds to stack

signals:
    void running();
    void initialized();
    void setuped();
    void readied();

public: // const

public: // non-const

public: // pointers
    Label * mainLabel();
    Application * app() const;
    QGridLayout * mainGrid();
    QStackedLayout * mainStack();
    QStatusBar * statusBar();
private:
    Application * mpApplication=nullptr;
    Contents cmContents=$null;
    QWidget * mpMainWidget=nullptr;
    QGridLayout * mpMainGrid=nullptr;
    QStackedLayout * mpMainStack=nullptr;
    QQTextEdit * mpMainEdit=nullptr;
    QQTextDocument * mpMainDoc=nullptr;
    Label * mpMainLabel=nullptr;
    QStatusBar * mpStatusBar=nullptr;
};

inline Label *MainWindow::mainLabel() { Q_CHECK_PTR(mpMainLabel); return mpMainLabel; }
inline Application *MainWindow::app() const { Q_CHECK_PTR(mpApplication); return mpApplication; }
inline QGridLayout *MainWindow::mainGrid()  { Q_CHECK_PTR(mpMainGrid); return mpMainGrid; }
inline QStackedLayout *MainWindow::mainStack()  { Q_CHECK_PTR(mpMainStack); return mpMainStack; }
inline QStatusBar *MainWindow::statusBar() { Q_CHECK_PTR(mpStatusBar); return mpStatusBar; }


#pragma once

#include <QMainWindow>

#include <QFlags>
#include <QGridLayout>
#include <QWidget>
//class QCoreApplication;
class QGridLayout;

class QQApplication;
class Size;

#include "Label.h"
#include "QQTextDocument.h"
#include "QQTextEdit.h"

class QQMainWindow : public QMainWindow
{
    Q_OBJECT
public: // types
    enum Content
    {
        $null               = 0,
        Grid                = 0x00000001,
        TextEdit            = 0x00000100,
        TextDocument        = 0x00000200,
        ImageLabel          = 0x00000800,
        LogStderr           = 0x00010000,
        ReadOnly            = 0x80000000,
    };
    Q_DECLARE_FLAGS(Contents, Content);
    Q_FLAG(Contents);

public: // ctors
    explicit QQMainWindow(const Contents cf, QQApplication *app);

public slots:
    virtual void run();
    virtual void initialize();
    virtual void setup();
    virtual void ready();

signals:
    void running();
    void initialized();
    void setuped();
    void readied();

public: // const
    Size mainSize() const;

public: // pointers
    Label * mainLabel();
    QQApplication * app() const;

private:
    QQApplication * mpApplication=nullptr;
    Contents cmContents=$null;
    QWidget * mpMainWidget=nullptr;
    QGridLayout * mpMainGrid=nullptr;
    QQTextEdit * mpMainEdit=nullptr;
    QQTextDocument * mpMainDoc=nullptr;
    Label * mpMainLabel=nullptr;
    Size mMainWinSize=Size(512);
};

inline Size QQMainWindow::mainSize() const { return mMainWinSize; }
inline Label *QQMainWindow::mainLabel() { Q_CHECK_PTR(mpMainLabel); return mpMainLabel; }
inline QQApplication *QQMainWindow::app() const { Q_CHECK_PTR(mpApplication); return mpApplication; }


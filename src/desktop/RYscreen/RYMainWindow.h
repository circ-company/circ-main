#pragma once

#include <QMainWindow>

class QHBoxLayout;

#include <Size.h>
#include <Types.h>

class RYApplication;
class ryFaceGrid;
class ryTaskBar;

class RYMainWindow : public QMainWindow
{
    Q_OBJECT

public: // ctors
    RYMainWindow(RYApplication *parent);
    ~RYMainWindow();


public slots:
    void run();
    void initialize();
    void setup();
    void ready();

signals:
    void running();
    void initialized();
    void setuped();
    void readied();

public: // const
    const Size screenSize() const;
    const Size faceSize() const;

public slots: // non-const

public: // pointers
    RYApplication * app();
    QHBoxLayout * layout();
    ryTaskBar * taskBar();
    ryFaceGrid * faceGrid();

private:
    const Size cmScreenSize=Size(1340, 800);
    const Size cmFaceSize=Size(128);
    RYApplication * mpApplication=nullptr;
    QHBoxLayout * mpBoxLayout=nullptr;
    QWidget * mpMainWidget=nullptr;
    ryTaskBar * mpTaskBar=nullptr;
    ryFaceGrid * mpFaceGrid=nullptr;
};

inline const Size RYMainWindow::screenSize() const  { return cmScreenSize; }
inline const Size RYMainWindow::faceSize() const { return cmFaceSize; }
inline RYApplication *RYMainWindow::app() {  Q_CHECK_PTR(mpApplication); return mpApplication; }
inline QHBoxLayout *RYMainWindow::layout() {  Q_CHECK_PTR(mpBoxLayout); return mpBoxLayout; }
inline ryTaskBar *RYMainWindow::taskBar() {  Q_CHECK_PTR(mpTaskBar); return mpTaskBar; }
inline ryFaceGrid *RYMainWindow::faceGrid(){ Q_CHECK_PTR(mpFaceGrid); return mpFaceGrid; }

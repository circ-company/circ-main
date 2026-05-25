#pragma once

#include <QApplication>

class QQMainWindow;

class QQApplication : public QApplication
{
    Q_OBJECT
protected:
    QQApplication(int &argc, char **argv);

public: // pointers
    QQMainWindow * mainWindow();
    void mainWindow(QQMainWindow * pMW);

private:
    QQMainWindow * mpMainWindow=nullptr;

};

inline QQMainWindow *QQApplication::mainWindow() { Q_CHECK_PTR(mpMainWindow); return mpMainWindow; }
inline void QQApplication::mainWindow(QQMainWindow *pMW) { Q_CHECK_PTR(pMW); mpMainWindow = pMW; }

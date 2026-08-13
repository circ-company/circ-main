#pragma once

#include <QApplication>

#include <QDir>
#include <QImage>
#include <QTimer>

#include <FileInfo.h>
#include <FileInfoList.h>
#include <LabelMap.h>

class irViewMainWindow;

class Application : public QApplication
{
    Q_OBJECT
public:
    Application(int &argc, char **argv);

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

public: // const

public: // non-const

public: // pointers
    irViewMainWindow * mainWindow();

private:
    void initActions();

private:
    irViewMainWindow * mpMainWindow=nullptr;
    FileInfoList mFileList;
    LabelMap mLabelMap;
};

inline irViewMainWindow *Application::mainWindow() { Q_CHECK_PTR(mpMainWindow); return mpMainWindow; }

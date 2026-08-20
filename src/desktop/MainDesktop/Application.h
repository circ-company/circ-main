#pragma once

#include <QQApplication.h>
#include <QObject>

#include <QDir>
#include <QImage>
#include <QTimer>

#include <ExeSupport.h>
#include <FileInfo.h>
#include <FileInfoList.h>
class cvODCatalog;

class LoyaltyDisplayScreen;

class Application : public QQApplication
{
    Q_OBJECT
public:
    Application(int &argc, char **argv);

public slots:
    virtual void run() final;
    virtual void initialize() final;
    virtual void setup() final;
    virtual void start() final;
    virtual void processFile() final;

signals:
    void running();
    void initialized();
    void started();
    void processedFile(const FileInfo fi, const QImage qi);

public: // const

public: // non-const

public: // pointers
    void mainWindow(LoyaltyDisplayScreen * pMW);
    LoyaltyDisplayScreen * mainWindow();
    cvODCatalog * catalog();
    QDir mainDir(); // arg[1]

private:
    ExeSupport mExeSupport;
    LoyaltyDisplayScreen * mpMainWindow=nullptr;
    cvODCatalog * mpCatalog=nullptr;
    QDir mMainDir; // arg[1]
    QDir::Filters mDirFilters = QDir::Files | QDir::NoDotAndDotDot
                                | QDir::Readable | QDir::AllDirs;
    FileInfoList mFileList;
};

inline LoyaltyDisplayScreen *Application::mainWindow() { Q_CHECK_PTR(mpMainWindow); return mpMainWindow; }
inline cvODCatalog *Application::catalog() {  Q_CHECK_PTR(mpCatalog); return mpCatalog; }
inline QDir Application::mainDir() { return mMainDir; }
inline void Application::mainWindow(LoyaltyDisplayScreen *pMW) { Q_CHECK_PTR(pMW); mpMainWindow = pMW; }

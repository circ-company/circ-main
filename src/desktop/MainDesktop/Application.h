#pragma once

#include <QQApplication.h>
#include <QObject>

#include <QDir>
#include <QImage>

#include <FileInfo.h>
#include <DirLoader.h>

class MainWindow;

class Application : public QQApplication
{
    Q_OBJECT
public:
    Application(int argc, char *argv[]);

public slots:
    virtual void run() final;
    virtual void initialize() final;
    virtual void start() final;
    virtual void processFile(const FileInfo fi) final;

signals:
    void running();
    void initialized();
    void started();
    void processedFile(const FileInfo fi, const QImage qi);

public: // const

public: // non-const

public: // pointers
    void mainWindow(MainWindow * pMW);
    MainWindow * mainWindow();
    DirLoader * dirLoader();

private:
    MainWindow * mpMainWindow=nullptr;
    QDir mMainDir; // arg[1]
    QDir::Filters mDirFilters = QDir::Files | QDir::NoDotAndDotDot
                                | QDir::Readable | QDir::AllDirs;
    DirLoader *mpDirLoader=nullptr;
};

inline MainWindow *Application::mainWindow() { Q_CHECK_PTR(mpMainWindow); return mpMainWindow; }
inline void Application::mainWindow(MainWindow *pMW) { Q_CHECK_PTR(pMW); mpMainWindow = pMW; }
inline DirLoader *Application::dirLoader() { Q_CHECK_PTR(mpDirLoader); return mpDirLoader; }

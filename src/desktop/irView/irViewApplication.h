#pragma once

#include <QApplication>

#include <QDir>
#include <QImage>
#include <QTimer>

#include <ActionManager.h>
#include <FileInfo.h>
#include <FileInfoList.h>
#include <LabelMap.h>

class irViewMainWindow;

class irViewApplication : public QApplication
{
    Q_OBJECT
public:
    irViewApplication(int &argc, char **argv);

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
    void fileOpened(const FileInfo &fi);
    void dirOpened(const FileInfo &fi);
    void fileClosed(const FileInfo &fi);

public: // const
    QDir currentDir() const;

public: // non-const

public: // pointers
    irViewMainWindow * mainWindow();
    const ActionManager & actmgr() const;
    ActionManager & actmgr();

private slots:
    void fileOpen();
    void dirOpen();
    void fileClose();
    void fileExit();

private:
    void initActions();
    void connectActions();

private:
    irViewMainWindow * mpMainWindow=nullptr;
    ActionManager mActionManager;
    FileInfo mCurrentDir;
    FileInfoList mFileList;
    LabelMap mLabelMap;
};

inline QDir irViewApplication::currentDir() const { return mCurrentDir.dir(); }
inline irViewMainWindow *irViewApplication::mainWindow() { Q_CHECK_PTR(mpMainWindow); return mpMainWindow; }
inline const ActionManager &irViewApplication::actmgr() const { return mActionManager; }
inline ActionManager &irViewApplication::actmgr() { return mActionManager; }

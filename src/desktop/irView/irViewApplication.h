#pragma once

#include <QApplication>

#include <QDir>
#include <QImage>
#include <QTimer>

#include <ActionManager.h>
#include <FileInfo.h>
#include <FileInfoList.h>
#include <Image.h>
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
    void openImageFile(const FileInfo &aFI);

signals:
    void running();
    void initialized();
    void setuped();
    void started();
    void imageOpened(const Key aKey, const Image aImage);

public: // const
    QDir currentDir() const;

public: // non-const

public: // pointers
    irViewMainWindow * mainWindow();
    ActionManager * actmgr();

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
    KeyMapT<Image> mKeyImageMap;
};

inline QDir irViewApplication::currentDir() const { return mCurrentDir.dir(); }
inline irViewMainWindow *irViewApplication::mainWindow() { Q_CHECK_PTR(mpMainWindow); return mpMainWindow; }
inline ActionManager * irViewApplication::actmgr() { return & mActionManager; }

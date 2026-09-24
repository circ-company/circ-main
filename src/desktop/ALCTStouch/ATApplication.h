#pragma once

#include <QApplication>

#include <QFileInfoList>

#include <StdRandom.h>
#include <VersionInfo.h>

class ATMainWindow;

class ATApplication : public QApplication
{
    Q_OBJECT
public: // ctors
    ATApplication(int &argc, char **argv, int f=ApplicationFlags);

public slots:
    void start();
    void showNext();

signals:
    void starting();
    void started();

public: // const
    VersionInfo ver() const;

public: // non-const

public: // pointers
    void mainWindow(ATMainWindow * pMW);
    ATMainWindow * mainWindow();

private:
    ATMainWindow * mpMainWindow=nullptr;
    VersionInfo cmVersionInfo;
    QFileInfoList mFileInfos1, mFileInfos2;
    StdRandom mStdRandom;
};

inline VersionInfo ATApplication::ver() const { return cmVersionInfo; }



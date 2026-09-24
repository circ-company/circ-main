#include "ATApplication.h"

#include <QTimer>

#include <Image.h>
#include <Log.h>

#include "ATMainWindow.h"
#include "../../version.h"
#include "version.h"

ATApplication::ATApplication(int &argc, char **argv, int f)
    : QApplication(argc, argv, f)
    , cmVersionInfo(VER_MAJOR, VER_MINOR, VER_RELEASE,
                    VER_BRANCH, VER_BUILD, VER_BRANCHNAME,
                    VER_APPNAME, VER_ORGNAME, VER_COMMENT)
{
    setObjectName("ATApplication");
}

void ATApplication::start()
{
    FNENTER();
    FNEMIT("starting");
    emit starting();

    mainWindow()->initialize();

    QDir tDir1(arguments().value(1, "/home/code/repo/circ-doc/WadaProj/"
                                    "AnLoCuTraS/BByCustomer/01/"));
    DUMPVAR(tDir1.absolutePath());
    DUMPVAR(tDir1.exists());
    DUMPVAR(tDir1.isReadable());
    mFileInfos1 = tDir1.entryInfoList(Image::dirEntryFilters(), QDir::Files);

    QDir tDir2(arguments().value(2, "/home/code/repo/circ-doc/WadaProj/"
                                    "AnLoCuTraS/BByCustomer/02/"));
    DUMPVAR(tDir2.absolutePath());
    DUMPVAR(tDir2.exists());
    DUMPVAR(tDir2.isReadable());
    mFileInfos2 = tDir2.entryInfoList(Image::dirEntryFilters(), QDir::Files);

    mStdRandom.set(StdRandom::Range(0, 3));
    QTimer::singleShot(5000, this, &ATApplication::showNext);
    FNEMIT("started");
    emit started();
    FNRTNVOID();
}

void ATApplication::showNext()
{
    const Index cRandomIx = mStdRandom.take();
//    DUMPVAR(cRandomIx);
    QString tFName;
    switch (cRandomIx)
    {
    case 1:
        if ( ! mFileInfos1.isEmpty())
            tFName = mFileInfos1.takeFirst().filePath();
        break;
    case 2:
        if ( ! mFileInfos2.isEmpty())
            tFName = mFileInfos2.takeFirst().filePath();
        break;
    default:
        // skip for interestingness
        break;
    }

    if ( ! tFName.isEmpty())
    {
        DUMPVAR(tFName);
        QImage tImage(tFName);
        EXPECTNOT(tImage.isNull());
        mainWindow()->showImage(tImage);
    }

    if ( ! mFileInfos1.isEmpty() && ! mFileInfos2.isEmpty())
        QTimer::singleShot(250, this, &ATApplication::showNext);
}

void ATApplication::mainWindow(ATMainWindow *pMW)
{
    CKPOINTER(pMW);
    mpMainWindow = pMW;

}

ATMainWindow *ATApplication::mainWindow()
{
    CKPOINTER(mpMainWindow);
    return mpMainWindow;
}

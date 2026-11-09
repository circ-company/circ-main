#include "RYApplication.h"

#include <QAction>
#include <QTimer>

#include <Log.h>

RYApplication::RYApplication(int argc, char * argv[])
    : Application(argc, argv)
{
    FNENTER();
    setObjectName("RYApplication");
    QTimer::singleShot(100, this, &RYApplication::initialize);
}

void RYApplication::initialize()
{
    FNENTER();
    Application::initialize();
    if (argCount() < 1)
        mInputDir.cd("../FaceIn1");
    else
        mInputDir.cd(argAt(0));
    EXPECTEQ(true, mInputDir.isReadable());
    EXPECTNOT(mInputDir.isEmpty());
    FNEMIT("initialized");
    FNRTNVOID();

    QTimer::singleShot(100, this, &RYApplication::setup);
    emit initialized();
}

void RYApplication::setup()
{
    FNENTER();
    Application::setup();
    const QStringList cFileExtFilters = QStringList() << "*.jpg" << "*.png";
    mFIList = mInputDir.entryInfoList(cFileExtFilters);
    FNRTNVOID();
    emit setuped();
}

void RYApplication::start()
{
    FNENTER();
    Application::start();

    FNRTNVOID();
    emit started();
}

void RYApplication::processFile()
{
    FNENTER();
    Application::processFile();

    FNRTNVOID();
    emit processedFile(QFileInfo());
}

void RYApplication::finish()
{
    FNENTER();
    Application::processFile();

    FNRTNVOID();
    emit finished()    ;
}


#include "LoyaltyDisplayApplication.h"

#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QPixmap>
#include <QLabel>
#include <QThread>
#include <QTimer>

#include <Log.h>
#include <Image.h>
#include <Size.h>
#include <StdRandom.h>

#include "BaseLoyaltyDisplayPage.h"
#include "FileImageSource.h"
#include "LoyaltyDisplayScreen.h"
#include "../../version.h"
#include "version.h"

LoyaltyDisplayApplication::LoyaltyDisplayApplication(int &argc, char **argv)
    : QApplication{argc, argv}
    , cmVersion(VER_MAJOR, VER_MINOR, VER_RELEASE,
                VER_BRANCH, VER_BUILD, VER_BRANCHNAME,
                LDVER_APPNAME, LDVER_ORGNAME, LDVER_COMMENT)
{
    LOG->initialize();
    FNENTER();
    setApplicationName(tr("AnLoCuTraS Touch Screen"));
    setApplicationDisplayName(tr(LDVER_PRODUCT));
    setApplicationVersion(cmVersion.toString());
    setOrganizationName(cmVersion.orgname());
    setOrganizationDomain("CIRC-CO.com");
    FNRTNVOID();
}

LoyaltyDisplayApplication::~LoyaltyDisplayApplication()
{
    if (mpScreen) mpScreen->deleteLater();
}

void LoyaltyDisplayApplication::start()
{
    // QTimer from main.cpp
    FNENTER();
    ASSERT(setConnections());

#if 0
    QCommandLineOption tOptSize(QStringList() << "size" << "s",
                                "Total Screen Resolution", "1280,800");
    QCommandLineParser tParser;
    tParser.addOption(tOptSize);
    tParser.process(arguments());
    const Size cScreenSize(tParser.value(tOptSize));
    screen()->screenSize(cScreenSize);
#endif

    DUMPVAR(arguments().count());
    QStringList tArgs = arguments();
    tArgs.removeFirst(); // take off exe filepath
    foreach (const QString cArg, tArgs)
    {
        DUMPVAR(cArg);
        const QUrl cUrl(cArg);
        DUMPVAR(cUrl.toLocalFile());
        const QDir cDir(cUrl.toLocalFile());
        DUMPVAR(cDir.absolutePath());
        DUMPVAR(cDir.isReadable());
        if (cDir.isReadable())
            mArguments.append(cDir.absolutePath());
    }
    DUMPVAR(mArguments.count());
    FNEMIT("started");
    emit started();
    FNRTNVOID();
}

void LoyaltyDisplayApplication::initialize()
{
    FNENTER();

    while ( ! mArguments.isEmpty())
    {
        const QString cArg = mArguments.takeFirst();
        DUMPVAR(cArg);
        const QFileInfo cFI(cArg);
        DUMPVAR(cFI.absoluteFilePath());
        QDir tDir = QDir(cFI.absoluteFilePath());
        DUMPVAR(tDir.absolutePath());
        QStringList tDirNames = tDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
        DUMPVAR(tDirNames.count());
        DUMPVAR(tDirNames.join(' '));
        foreach (const QString cDirName, tDirNames)
            mArguments.append(tDir.absoluteFilePath(cDirName));
        QStringList tFileNames = tDir.entryList(QDir::Files);
        DUMPVAR(tFileNames.count());
//        DUMPVAR(tFileNames.join(' '));
        if ( ! tFileNames.isEmpty())
        {
            DUMPVAR(tDir.absolutePath());
            const Key cKey(tDir.absolutePath());
            mKeyDirMap.insert(cKey, tDir);
        }
    }

    FNEMIT("initialized");
    emit initialized();
    FNRTNVOID();
}

void LoyaltyDisplayApplication::setup()
{
    FNENTER();

    mDirKeySourceMap.clear();
    KeyList tKeyList = mKeyDirMap.keys();
    while ( ! tKeyList.isEmpty())
    {
        const Key cKey = tKeyList.takeFirst();
        const QDir cDir = mKeyDirMap.value(cKey);
        FileImageSource * pSource = new FileImageSource(cDir, this);
        pSource->readSource();
        DUMPVAR(int(pSource->count()));
        mDirKeySourceMap.insert(cKey, pSource);
    }

    FNEMIT("setupd");
    emit setupd();
    FNRTNVOID();
}

void LoyaltyDisplayApplication::go()
{
    FNENTER();

    FNEMIT("going");
    emit going();

    screen()->run();

    DUMPVAR(sourceList().count());
    StdRandom tRandom(sourceList().count());
    while ( ! sourceList().isEmpty())
    {
        Index tIx = tRandom.take();
        DUMPVAR(tIx);
        if (tIx < sourceList().count())
        {
            BaseImageSource * pSource = sourceList().at(tIx);
            DUMPVAR(pSource->key()());
            pSource->checkSource();
            Image tImage = pSource->take();
            DUMPVAR(tImage.fileInfo().toString());
            DUMPVAR(tImage.toQImage().size());
            if ( ! tImage.isNull())
            {
#if 1
                QLabel * pLabel = new QLabel("LDApp::go() Label", screen());
                QPixmap tPixmap = QPixmap::fromImage(tImage.toQImage()
                    .scaled(screen()->faceSize()));
                screen()->setCentralWidget(pLabel);
                screen()->update();
                screen()->show();
#else
                BaseLoyaltyDisplayPage * pPage = screen()->page();
                DUMPVAR(pPage->ecc().aText()());
                pPage->showImage(tImage.id().key(), tImage);
#endif
            }
        }
        // TODO("How to delay 250~1500msec");
    }


    FNRTNVOID();
}

void LoyaltyDisplayApplication::showNext()
{
#if 0
    FNENTER();
    Count tSourceCount = mDirKeySourceMap.count();
    StdRandom tKeyRowRandom(500 * (tSourceCount + (tSourceCount >> 2)));
    Index tKeyIndex = tKeyRowRandom.take();
    if (tKeyIndex < Index(tSourceCount))
    {
        const Key cDirKey
                = mDirKeySourceMap.allkeys().at(tKeyIndex);
        BaseImageSource * pSource
                = mDirKeySourceMap.value(cDirKey);
        pSource->checkSource();
        if (pSource->isEmpty())
        {
            mDirKeySourceMap.remove(cDirKey);
        }
        else
        {
            const Image cImage = pSource->take();
            WEXPECTNOT(cImage.isNull());
            DUMPVAR(cImage.fileInfo().toQFileInfo().absoluteFilePath());
            FNEMIT("showingImage");
            emit showingImage();
            FNEMIT("showImage");
            FNEMITARG("showImage", cDirKey(), "QString");
            emit showImage(cDirKey, cImage);
        }
    }
//    }
//    StdRandom tRandom(500, 1000);
  //  QTimer::singleShot(tRandom.take(), &LoyaltyDisplayApplication::showTime);
    FNRTNVOID();
#endif
}

void LoyaltyDisplayApplication::process(BaseImageSource *pSource)
{
    MUSTDO("Use or Lose");
    FNENTER();
    CKPOINTER(pSource);
    FNARG(pSource->key()(), "QString");

    pSource->initialize(BaseImageSource::Loop);
    FNEMIT("processing");
    FNEMITARG("processing", pSource->key()(), "QString");
    emit processing(pSource->key());

    pSource->run();

    FNRTNVOID();
}

QList<BaseImageSource *> LoyaltyDisplayApplication::sourceList() const
{
    return mDirKeySourceMap.values();
}

QDir LoyaltyDisplayApplication::takeDir()
{
    FNENTER();
    QDir result;
    qDebug() << mArguments;
    if ( ! mArguments.isEmpty())
        result = mArguments.takeFirst();
    DUMPVAR(result.isReadable());
    FNRTNVALUE(result.path(), "QString");
    return result;
}

void LoyaltyDisplayApplication::screen(LoyaltyDisplayScreen *pLDS)
{
    CKPOINTER(pLDS);
    mpScreen = pLDS;
}

LoyaltyDisplayScreen *LoyaltyDisplayApplication::screen()
{
    CKPOINTER(mpScreen);
    return mpScreen;
}

bool LoyaltyDisplayApplication::setConnections()
{
    FNENTER();
    TriBool result(true);
    result.expect(connect(this, &LoyaltyDisplayApplication::started,
                          screen(), &LoyaltyDisplayScreen::start));
    result.expect(connect(screen(), &LoyaltyDisplayScreen::started,
                          this, &LoyaltyDisplayApplication::initialize));
    result.expect(connect(this, &LoyaltyDisplayApplication::initialized,
                          screen(), &LoyaltyDisplayScreen::initialize));
    result.expect(connect(screen(), &LoyaltyDisplayScreen::initialized,
                          this, &LoyaltyDisplayApplication::setup));
    result.expect(connect(this, &LoyaltyDisplayApplication::setupd,
                          screen(), &LoyaltyDisplayScreen::setup));
    result.expect(connect(screen(), &LoyaltyDisplayScreen::setupd,
                          this, &LoyaltyDisplayApplication::go));
//    result.expect(connect(this, &LoyaltyDisplayApplication::going,
  //                        screen(), &LoyaltyDisplayScreen::run));
//    result.expect(connect(this, &LoyaltyDisplayApplication::showingImage,
  //                        this, &LoyaltyDisplayApplication::showNext));

    FNRTNVALUE(result.isTrue(), "bool");
    return result;
}

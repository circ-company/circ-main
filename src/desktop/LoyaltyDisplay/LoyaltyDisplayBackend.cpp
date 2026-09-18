#include "LoyaltyDisplayBackend.h"

#include <QCommandLineOption>
#include <QCommandLineParser>

#include <Log.h>
#include <Size.h>

#include "FileImageSource.h"
#include "LoyaltyDisplayScreen.h"
#include "../../version.h"
#include "version.h"

LoyaltyDisplayBackend::LoyaltyDisplayBackend(int &argc, char **argv)
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

LoyaltyDisplayBackend::~LoyaltyDisplayBackend()
{
    if (mpScreen) mpScreen->deleteLater();
}

void LoyaltyDisplayBackend::start()
{
    FNENTER();

    // TODO Camera URL(s) arguments
#if 0
    QCommandLineOption tOptSize(QStringList() << "size" << "s",
                                "Total Screen Resolution", "1280,800");
    QCommandLineParser tParser;
    tParser.addOption(tOptSize);
    tParser.process(arguments());
    const Size cScreenSize(tParser.value(tOptSize));
    screen()->screenSize(cScreenSize);
#endif
    ASSERT(setConnections());
    DUMPVAR(arguments().count());
    QStringList tArgs = arguments();
    tArgs.removeFirst(); // take off exe filepath
    foreach (const QString cArg, tArgs)
    {
        DUMPVAR(cArg);
        const Url cUrl(cArg);
        const FileInfo cFI(cUrl.localFlleInfo());
        const QDir cDir = cFI.dir();
        DUMPVAR(cDir.isReadable());
        if (cDir.isReadable())
            mDirArguments.append(cArg);
    }
    DUMPVAR(mDirArguments.count());
    FNEMIT("started");
    emit started();
    FNRTNVOID();
}

void LoyaltyDisplayBackend::initialize()
{
    FNENTER();

    FNEMIT("initialized");
    emit initialized();
    FNRTNVOID();
}

void LoyaltyDisplayBackend::setup()
{
    FNENTER();

    FNEMIT("setupd");
    emit setupd();
    FNRTNVOID();
}

void LoyaltyDisplayBackend::run()
{
    FNENTER();

    QDir tDir = takeDir();
    while (tDir != QDir())
    {
        PROGRESS("Processing Dir: " + tDir.path());
        FileImageSource * pSource = new FileImageSource(tDir, this);
        process(pSource);
        pSource->deleteLater();
        tDir = takeDir();
    }

    FNEMIT("running");
    emit running();
    FNRTNVOID();
}

void LoyaltyDisplayBackend::process(BaseImageSource *pSource)
{
    FNENTER();
    CKPOINTER(pSource);
    FNARG(pSource->key()(), "QString");

    pSource->initialize(BaseImageSource::Loop);
    FNEMIT("processing");
    FNEMITARG("processing", pSource->key()(), "QString");
    emit processing(pSource->key());

    pSource->run(1000);

    FNRTNVOID();
}

QDir LoyaltyDisplayBackend::takeDir()
{
    FNENTER();
    QDir result;
    qDebug() << mDirArguments;
    if ( ! mDirArguments.isEmpty())
        result = mDirArguments.takeFirst();
    DUMPVAR(result.isReadable());
    FNRTNVALUE(result.path(), "QString");
    return result;
}

void LoyaltyDisplayBackend::screen(LoyaltyDisplayScreen *pLDS)
{
    CKPOINTER(pLDS);
    mpScreen = pLDS;
}

LoyaltyDisplayScreen *LoyaltyDisplayBackend::screen()
{
    CKPOINTER(mpScreen);
    return mpScreen;
}

bool LoyaltyDisplayBackend::setConnections()
{
    FNENTER();
    TriBool result(true);
    result.expect(connect(this, &LoyaltyDisplayBackend::started,
                          screen(), &LoyaltyDisplayScreen::start));
    result.expect(connect(screen(), &LoyaltyDisplayScreen::started,
                          this, &LoyaltyDisplayBackend::initialize));
    result.expect(connect(this, &LoyaltyDisplayBackend::initialized,
                          screen(), &LoyaltyDisplayScreen::initialize));
    result.expect(connect(screen(), &LoyaltyDisplayScreen::initialized,
                          this, &LoyaltyDisplayBackend::setup));
    result.expect(connect(this, &LoyaltyDisplayBackend::setupd,
                          screen(), &LoyaltyDisplayScreen::setup));
    result.expect(connect(screen(), &LoyaltyDisplayScreen::setupd,
                          this, &LoyaltyDisplayBackend::run));
    result.expect(connect(this, &LoyaltyDisplayBackend::running,
                          screen(), &LoyaltyDisplayScreen::run));

    FNRTNVALUE(result.isTrue(), "bool");
    return result;
}

#include "LoyaltyDisplayBackend.h"

#include <QCommandLineOption>
#include <QCommandLineParser>

#include <Log.h>
#include <Size.h>

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

    FNEMIT("running");
    emit running();
    FNRTNVOID();
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

void LoyaltyDisplayBackend::screen(LoyaltyDisplayScreen *pLDS) { CKPOINTER(pLDS); mpScreen = pLDS; }
LoyaltyDisplayScreen *LoyaltyDisplayBackend::screen() { Q_ASSERT(mpScreen); return mpScreen; }
QStackedLayout *LoyaltyDisplayBackend::stack() { CKPOINTER(mpStack); return mpStack; }

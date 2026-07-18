#include "ExeSupport.h"

#include <QCoreApplication>

#include "CommandLine.h"
#include "Configuration.h"
#include "Options.h"
#include "Settings.h"

#include <version.h>

ExeSupport::ExeSupport(const QString &aAppName, QObject *parent)
    : QObject{parent}
    , mpCommandLine(new CommandLine(this))
    , mpConfiguration(new Configuration(this))
    , mpOptions(new Options(this))
    , mpSettings(new Settings(this))
    , mVersionInfo(VER_MAJOR, VER_MINOR, VER_RELEASE, VER_BRANCH,
                   VER_BUILD, VER_BRANCHNAME, VER_APPNAME, VER_ORGNAME,
                   VER_COPYRIGHT)
{
    setObjectName("ExeSupport");
    mVersionInfo.appname(aAppName);
    QCoreApplication::setApplicationName(ver().appname());
    QCoreApplication::setOrganizationName(ver().orgname());
    QCoreApplication::setApplicationVersion(ver().toString(VersionInfo::WithDotted));
}


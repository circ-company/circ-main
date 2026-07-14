#include "ExeSupport.h"

#include "CommandLine.h"
#include "Configuration.h"
#include "Options.h"
#include "Settings.h"

ExeSupport::ExeSupport(QObject *parent)
    : QObject{parent}
    , mpCommandLine(new CommandLine(this))
    , mpConfiguration(new Configuration(this))
    , mpOptions(new Options(this))
    , mpSettings(new Settings(this))
{
    setObjectName("ExeSupport");
}


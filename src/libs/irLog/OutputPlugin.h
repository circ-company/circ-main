#pragma once

#include <QObject>
#include "OutputInterface.h"

class OutputPlugin : public QObject, OutputInterface
{
    Q_OBJECT
//    Q_INTERFACES(OutputInterface)
    Q_PLUGIN_METADATA(IID "org.circ-co.libs.log"
                          "LogOutput."
                          "OutputInterface/1.0")

public:
    explicit OutputPlugin();

};

# BuildMainDesk.pro - Build Eclipse Face Processor and its libraries

TEMPLATE = subdirs

SUBDIRS +=              \
    libs/irBase         \
    libs/irLog          \
    libs/irMatGeo       \
    libs/irExe          \
    libs/irqNetwork     \
    libs/irqCore	\
    libs/irStore        \
    libs/irqXml         \
    libs/irTypes        \
    libs/irqGui         \
    libs/irqWidgets	\
    libs/QtCVcore       \
    libs/QtCVobjdetect  \
    libs/QtCVutils      \
    libs/irImage        \
    desktop/MainDesktop \

irBase.depends          =
irLog.depends           = irBase
irMatGeo.depends        =           irLog
irqNetwork.depends      = irBase    irLog
irqCore.depends         = irBase    irLog
irStore.depends         = irBase    irLog
irTypes.depends         = irBase    irLog                               irqCore     irqNetwork
irExe.depends           = irBase    irLog                                                       irStore
irqXml.depends          = irBase    irLog       irMatGeo    irTypes                             irStore
irqGui.depends          = irBase    irLog                   irTypes
irqWidgets.depends      = irBase    irLog       irMatGeo    irTypes
irImage.depends         = irBase ## TBD
QtCVobjdetect.depends   = irBase    irLog       irMatGeo    irTypes                             irStore     irqXml  QtCVcore
MainDesktop.depends     = irBase    irLog       irMatGeo    irTypes     irqCore     irqNetwork  irStore     irqXml  QtCVcore \
                            irqGui      irqWidgets      irImage         QtCVobjdetect





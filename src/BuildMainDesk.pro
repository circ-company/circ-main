# BuildMainDesk.pro - Build Eclipse Face Processor and its libraries

TEMPLATE = subdirs

SUBDIRS +=              \
    desktop/MainDesktop \
    libs/irBase         \
    libs/irImage        \
    libs/irLog          \
    libs/irMatGeo       \
    libs/irStore \
    libs/irStore        \
    libs/irqCore	\
    libs/irqGui         \
    libs/irqNetwork     \
    libs/irqWidgets	\
    libs/irTypes        \

irBase.depends          =
irMatGeo.depends        =
irLog.depends           = irBase
irqNetwork.depends      = irBase
irqCore.depends         = irBase
irTypes.depends         = irBase    irqCore     irqNetwork
irqGui.depends          = irBase    irTypes
irqWidgets.depends      = irBase    irLog       irMatGeo    irTypes
irStore.depends         = irBase    irLog
irImage.depends         = irBase
MainDesktop.depends     = irBase    irLog       irMatGeo    irqNetwork  irqCore \
                                                            irTypes   \
                            irqGui  irqWidgets  irStore     irImage





# BuildMainDesk.pro - Build Eclipse Face Processor and its libraries

TEMPLATE = subdirs

SUBDIRS +=              \
    desktop/MainDesktop \
    libs/irBase         \
    libs/irTypes        \
    libs/irMatGeo       \
    libs/irImage        \
    libs/irLog          \
    libs/irqCore	\
    libs/irqGui         \
    libs/irqNetwork     \
    libs/irqWidgets	\

irBase.depends          =
irMatGeo.depends        =
irqNetwork.depends      = irBase
irqCore.depends         = irBase
irTypes.depends         = irBase    irqCore     irqNetwork
irLog.depends           = irBase    irqNetwork  irTypes
irqGui.depends          = irBase    irTypes
irqWidgets.depends      = irBase    irMatGeo    irTypes
irImage.depends         = irBase
MainDesktop.depends     = irBase    irMatGeo    irqNetwork  irqCore irTypes irLog \
                            irqGui  irqWidgets  irImage





# BuildView.pro - Build Eclipse Face Processor and its libraries

TEMPLATE = subdirs

SUBDIRS +=              \
    libs/irBase         \
    libs/irLog          \
    libs/irMatGeo       \
    libs/irExe          \
    libs/irMsg          \
    libs/irqCore	\
    libs/irqNetwork     \
    libs/irStore        \
    libs/irqXml         \
    libs/irTypes        \
    libs/irqGui         \
    libs/irqWidgets	\
    libs/irImage        \
    desktop/LoyaltyDisplay      \

irBase.depends          =
irLog.depends           = irBase
irMatGeo.depends        =           irLog
irqCore.depends         = irBase    irLog
irqNetwork.depends      = irBase    irLog
irTypes.depends         = irBase    irLog                           \
            irqCore     irqNetwork
irStore.depends         = irBase    irLog
irMsg.depends           = irBase    irLog
irExe.depends           = irBase    irLog                                                       irStore
irqXml.depends          = irBase    irLog       irMatGeo    irTypes                             irStore
irqGui.depends          = irBase    irLog                   irTypes
irqWidgets.depends      = irBase    irLog       irMatGeo    irTypes
irImage.depends         = irBase    irLog
LoyaltyDisplay.depends  = irBase    irLog       irMatGeo    irTypes \
                irqCore       irStore     irqXml    irqGui          \
                    irqWidgets      irImage





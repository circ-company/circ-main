# BuildMainDesk.pro - Build irView Intermountain Research Image Viewer

TEMPLATE = subdirs

SUBDIRS +=              \
    libs/irBase         \
    libs/irLog          \
    libs/irMatGeo       \
    libs/irExe          \
    libs/irqCore	\
    libs/irStore        \
    libs/irTypes        \
    libs/irqGui         \
    libs/irqWidgets	\
    libs/irImage        \
    desktop/irView      \

irBase.depends          =
irLog.depends           = irBase
irMatGeo.depends        =           irLog
irqCore.depends         = irBase    irLog
irStore.depends         = irBase    irLog
irTypes.depends         = irBase    irLog                               irqCore     irqNetwork
irExe.depends           = irBase    irLog                                                       irStore
irqGui.depends          = irBase    irLog                   irTypes
irqWidgets.depends      = irBase    irLog       irMatGeo    irTypes
irImage.depends         = irBase ## TBD
irView.depends          = irBase    irLog       irMatGeo    irTypes     irqCore     irStore \
                            irqGui      irqWidgets      irImage





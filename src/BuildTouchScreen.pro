# BuildView.pro - Build Eclipse Face Processor and its libraries

TEMPLATE = subdirs

SUBDIRS +=              \
    libs/irBase         \
    libs/irColor        \
    libs/irImage        \
    libs/irExe          \
    libs/irLog          \
    libs/irMatGeo       \
    libs/irMsg          \
    libs/irqCore	\
    libs/irqNetwork     \
    libs/irqXml         \
    libs/irqGui         \
    libs/irqWidgets	\
    libs/irStore        \
    libs/irTouch        \
    libs/irTypes        \
    libs/QtCVutils      \
    libs/QtCVcore       \
    libs/QtCVimgcodecs  \
    libs/QtCVimgproc    \
    libs/QtCVutils      \
    libs/QtCVobjdetect  \
    libs/QtCVfacerec    \
    desktop/LoyaltyDisplay

irBase.depends          =
irLog.depends           = irBase
irMatGeo.depends        =           irLog
irqCore.depends         = irBase    irLog
irqNetwork.depends      = irBase    irLog
irTypes.depends         = irBase    irLog                           \
            irqCore     irqNetwork
irColor.depends         = irBase    irLog   irMatGeo    irTypes
irStore.depends         = irBase    irLog
irMsg.depends           = irBase    irLog
irExe.depends           = irBase    irLog                                                       irStore
irqXml.depends          = irBase    irLog   irMatGeo    irTypes                             irStore
irqGui.depends          = irBase    irLog               irTypes
irqWidgets.depends      = irBase    irLog   irMatGeo    irTypes
irTouch.depends         = irBase    irLog   irMatGeo    irTypes \
                                irColor
irImage.depends         = irBase    irLog
LoyaltyDisplay.depends  = irBase    irLog   irMatGeo    irTypes \
                irqCore irqNetwork      irColor     irStore \
                irqXml  irqGui  irqWidgets  irImage     irTouch





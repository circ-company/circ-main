# BuildMainDesk.pro - Build Eclipse Face Processor and its libraries

TEMPLATE = subdirs

SUBDIRS +=              \
    desktop/RYscreen \
    libs/ifBase         \
    libs/ifAcquire         \
    libs/ifDetect         \
    libs/ifGenerate         \
    libs/ifLocate         \
    libs/ifMatch         \
    libs/ifStore        \
    libs/irBase          \
    libs/irCore          \
    libs/irImage          \
    libs/irMsg          \
    libs/irLog          \
    libs/irMatGeo       \
    libs/irExe          \
    libs/irStore        \
    libs/irqXml         \
    libs/irTouch        \
    libs/irTypes        \
    libs/irqCore	   \
    libs/irqGui         \
    libs/irqWidgets	\
    libs/irqHelp     \
    libs/irqImage     \
    libs/irqPDF     \
    libs/irqPrint     \
    libs/irqSQL     \
    libs/irqState     \
    libs/irqSVG     \
    libs/QtCVcore       \
    libs/QtCVobjdetect  \
    libs/QtCVutils      \
    libs/QtCVfacerec       \
    libs/QtCVimgcodecs     \
    libs/QtCVimgproc  \
    libs/ryBase        \
    libs/ryWidgets

irBase.depends          =
irLog.depends           = irBase
irMatGeo.depends        =           irLog
irqNetwork.depends      = irBase    irLog
irqCore.depends         = irBase    irLog
irStore.depends         = irBase    irLog
irTypes.depends         = irBase    irLog   irqCore     irqNetwork
irExe.depends           = irBase    irLog   irStore
irqXml.depends          = irBase    irLog       irMatGeo    irTypes irStore
irqGui.depends          = irBase    irLog                   irTypes
irqWidgets.depends      = irBase    irLog       irMatGeo    irTypes
irImage.depends         = irBase ## TBD
QtCVobjdetect.depends   = irBase    irLog       irMatGeo    irTypes    \
                            irStore     irqXml  QtCVcore
ryScreen.depends        = irBase    irLog       irMatGeo    irTypes     irqCore \
                            irqNetwork  irStore     irqXml  QtCVcore \
                            irqGui      irqWidgets      irImage      \
                            QtCVobjdetect





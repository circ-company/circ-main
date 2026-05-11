QT += widgets
TEMPLATE = lib
DEFINES += IRQSVG_LIBRARY

include(../libs.pri)

SOURCES += \
    irqSVG.cpp

HEADERS += \
    irqSVG_global.h \
    irqSVG.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

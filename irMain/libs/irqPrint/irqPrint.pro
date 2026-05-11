QT += gui
TEMPLATE = lib
DEFINES += IRQPRINT_LIBRARY

include(../libs.pri)

SOURCES += \
    irqPrint.cpp

HEADERS += \
    irqPrint_global.h \
    irqPrint.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

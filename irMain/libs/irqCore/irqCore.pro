QT -= gui
TEMPLATE = lib
DEFINES += IRQCORE_LIBRARY

include(../libs.pri)

SOURCES += \
    irqCore.cpp

HEADERS += \
    irqCore_global.h \
    irqCore.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

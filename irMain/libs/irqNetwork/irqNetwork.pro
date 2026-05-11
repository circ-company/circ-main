QT -= gui
TEMPLATE = lib
DEFINES += IRQNETWORK_LIBRARY

include(../libs.pri)

SOURCES += \
    irqNetwork.cpp

HEADERS += \
    irqNetwork_global.h \
    irqNetwork.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

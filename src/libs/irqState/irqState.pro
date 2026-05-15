QT -= gui
TEMPLATE = lib
DEFINES += IRQSTATE_LIBRARY

include(../libs.pri)

SOURCES += \
    irqState.cpp

HEADERS += \
    irqState_global.h \
    irqState.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

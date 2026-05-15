QT -= gui
TEMPLATE = lib
DEFINES += IRQHELP_LIBRARY

include(../libs.pri)

SOURCES += \
    irqHelp.cpp

HEADERS += \
    irqHelp_global.h \
    irqHelp.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

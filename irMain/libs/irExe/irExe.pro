QT -= gui
TEMPLATE = lib
DEFINES += IREXE_LIBRARY

include(../libs.pri)

SOURCES += \
    irExe.cpp

HEADERS += \
    irExe_global.h \
    irExe.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

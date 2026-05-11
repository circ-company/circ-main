QT -= gui
TEMPLATE = lib
DEFINES += IRCORE_LIBRARY

include(../libs.pri)

SOURCES += \
    irCore.cpp

HEADERS += \
    irCore_global.h \
    irCore.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

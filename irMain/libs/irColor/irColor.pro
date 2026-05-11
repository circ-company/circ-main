QT -= gui
TEMPLATE = lib
DEFINES += IRCOLOR_LIBRARY

include(../libs.pri)

SOURCES += \
    irColor.cpp

HEADERS += \
    irColor_global.h \
    irColor.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

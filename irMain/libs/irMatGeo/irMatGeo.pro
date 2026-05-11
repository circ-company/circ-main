QT -= gui
TEMPLATE = lib
DEFINES += IRMATGEO_LIBRARY

include(../libs.pri)

SOURCES += \
    irMatGeo.cpp

HEADERS += \
    irMatGeo_global.h \
    irMatGeo.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

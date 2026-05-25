QT -= gui
TEMPLATE = lib
DEFINES += IRMATGEO_LIBRARY

include(../libs.pri)
include(../../useTypes.pri)

SOURCES += \
    Point.cpp \
    Rational.cpp \
    SCRect.cpp \
    Size.cpp \
    irMatGeo.cpp

HEADERS += \
    Point.h \
    Rational.h \
    SCRect.h \
    Size.h \
    irMatGeo_global.h \
    irMatGeo.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

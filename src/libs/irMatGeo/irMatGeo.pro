QT -= gui
TEMPLATE = lib
DEFINES += IRMATGEO_LIBRARY

include(../libs.pri)
include(../../useTypes.pri)

SOURCES += \
    Aspect.cpp \
    Point.cpp \
    Rational.cpp \
    Rect.cpp \
    SCRect.cpp \
    Size.cpp \
    irMatGeo.cpp

HEADERS += \
    Aspect.h \
    Point.h \
    Rational.h \
    Rect.h \
    SCRect.h \
    Size.h \
    irMatGeo_global.h \
    irMatGeo.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

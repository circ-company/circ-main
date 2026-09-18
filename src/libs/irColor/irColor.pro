QT *= gui
QT *= widgets
TEMPLATE = lib
DEFINES += IRCOLOR_LIBRARY

include(../libs.pri)
include(../../useBase.pri)
include(../../useLog.pri)
include(../../useMatGeo.pri)
include(../../useTypes.pri)
include(../libs.pri)

SOURCES += \
    Color.cpp \
    ColorWheel.cpp \
    irColor.cpp

HEADERS += \
    Color.h \
    ColorWheel.h \
    irColor_global.h \
    irColor.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

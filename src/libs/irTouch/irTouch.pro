QT *= gui
QT *= widgets
TEMPLATE = lib
DEFINES += IRTOUCH_LIBRARY

include(../libs.pri)
include(../../useBase.pri)
include(../../useLog.pri)
include(../../useMatGeo.pri)
include(../../useTypes.pri)
include(../../useColor.pri)

SOURCES += \
    Button.cpp \
    GenerateIcon.cpp \
    GenerateIconScheme.cpp \
    irTouch.cpp

HEADERS += \
    Button.h \
    GenerateIcon.h \
    GenerateIconScheme.h \
    irTouch_global.h \
    irTouch.h

TRANSLATIONS += \
    irTouch_en_US.ts

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

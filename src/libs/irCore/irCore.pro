QT -= gui
TEMPLATE = lib
DEFINES += IRCORE_LIBRARY

include(../libs.pri)
include(../../useBase.pri)
include(../../useTypes.pri)

SOURCES += \
    ObjectHelper.cpp \
    irCore.cpp

HEADERS += \
    ObjectHelper.h \
    irCore_global.h \
    irCore.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

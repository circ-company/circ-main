QT -= gui
TEMPLATE = lib
DEFINES += IRTYPES_LIBRARY

include(../libs.pri)
include(../../useBase.pri)
include(../../useLog.pri)

SOURCES += \
    RandomGenerator.cpp \
    Signum.cpp \
    irTypes.cpp

HEADERS += \
    CircularArray.h \
    MetaType.h \
    RandomGenerator.h \
    Signum.h \
    irTypes_global.h \
    irTypes.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

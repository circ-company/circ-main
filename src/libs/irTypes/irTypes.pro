QT -= gui
TEMPLATE = lib
DEFINES += IRTYPES_LIBRARY

include(../libs.pri)
include(../../useBase.pri)
include(../../useLog.pri)
include(../../useQCore.pri)
include(../../useQNetwork.pri)

SOURCES += \
    RandomGenerator.cpp \
    Result.cpp \
    Signum.cpp \
    StatusItem.cpp \
    StatusItemList.cpp \
    StatusCode.cpp \
    irTypes.cpp

HEADERS += \
    CircularArray.h \
    MetaType.h \
    RandomGenerator.h \
    Result.h \
    StatusItem.h \
    StatusItemList.h \
    Signum.h \
    StatusCode.h \
    irTypes_global.h \
    irTypes.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

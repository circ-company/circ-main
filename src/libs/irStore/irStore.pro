QT *= gui
TEMPLATE = lib
DEFINES += IRSTORE_LIBRARY

include(../libs.pri)
include(../../useBase.pri)
include(../../useLog.pri)
include(../../useTypes.pri)


SOURCES += \
    BaseFile.cpp \
    DataFile.cpp \
    JsonFile.cpp \
    NameFilters.cpp \
    TextFile.cpp \
    irStore.cpp

HEADERS += \
    BaseFile.h \
    DataFile.h \
    JsonFile.h \
    NameFilters.h \
    TextFile.h \
    irStore_global.h \
    irStore.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

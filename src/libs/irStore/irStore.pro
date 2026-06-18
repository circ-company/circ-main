QT *= gui
TEMPLATE = lib
DEFINES += IRSTORE_LIBRARY

include(../libs.pri)
include(../../useBase.pri)
include(../../useLog.pri)
include(../../useTypes.pri)


SOURCES += \
    DirLoader.cpp \
    File.cpp \
    NameFilters.cpp \
    irStore.cpp

HEADERS += \
    DirLoader.h \
    File.h \
    NameFilters.h \
    irStore_global.h \
    irStore.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

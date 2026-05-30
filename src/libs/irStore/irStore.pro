QT *= gui
TEMPLATE = lib
DEFINES += IRSTORE_LIBRARY

include(../libs.pri)
include(../../useBase.pri)
include(../../useLog.pri)


SOURCES += \
    DirLoader.cpp \
    irStore.cpp

HEADERS += \
    DirLoader.h \
    irStore_global.h \
    irStore.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

QT *= gui
TEMPLATE = lib
DEFINES += IRSTORE_LIBRARY

include(../libs.pri)
include(../../useBase.pri)
include(../../useLog.pri)
include(../../useTypes.pri)
include(../../useImage.pri)


SOURCES += \
    BaseFile.cpp \
    BaseImageSource.cpp \
    DataFile.cpp \
    FileImageSource.cpp \
    JsonFile.cpp \
    NameFilters.cpp \
    TextFile.cpp \
    irStore.cpp

HEADERS += \
    BaseFile.h \
    BaseImageSource.h \
    DataFile.h \
    FileImageSource.h \
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

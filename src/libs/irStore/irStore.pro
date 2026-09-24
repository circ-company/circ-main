QT *= gui
TEMPLATE = lib
DEFINES += IRSTORE_LIBRARY

include(../libs.pri)
include(../../useBase.pri)
include(../../useLog.pri)
include(../../useTypes.pri)
include(../../useImage.pri)


SOURCES += \
    AnonymousId.cpp \
    BaseFile.cpp \
    BaseImageSource.cpp \
    DataFile.cpp \
    FaceId.cpp \
    FileImageSource.cpp \
    FrameId.cpp \
    ImageCache.cpp \
    ImageCacheStore.cpp \
    JsonFile.cpp \
    MemoryImageCache.cpp \
    NameFilters.cpp \
    PersonId.cpp \
    TextFile.cpp \
    irStore.cpp

HEADERS += \
    AnonymousId.h \
    BaseFile.h \
    BaseImageSource.h \
    DataFile.h \
    FaceId.h \
    FileImageSource.h \
    FrameId.h \
    ImageCache.h \
    ImageCacheStore.h \
    JsonFile.h \
    MemoryImageCache.h \
    NameFilters.h \
    PersonId.h \
    TextFile.h \
    irStore_global.h \
    irStore.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

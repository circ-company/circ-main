QT -= gui
TEMPLATE = lib
DEFINES += IRBASE_LIBRARY

include(../libs.pri)

SOURCES += \
    AText.cpp \
    CText.cpp \
    CTextList.cpp \
    Enumeration.cpp \
    Severity.cpp \
    UText.cpp \
    VersionInfo.cpp \
    irBase.cpp

HEADERS += \
    ../../version.h \
    AText.h \
    CText.h \
    CTextList.h \
    DualMap.h \
    Enumeration.h \
    Named.h \
    Severity.h \
    Types.h \
    UText.h \
    VersionInfo.h \
    irBase_global.h \
    irBase.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../../BINDIR.pri \
    ../../BLDCFG.pri \
    ../../CVMAJOR.pri \
    ../../CVVERSION.pri \
    ../../DESTDIR.pri \
    ../../LIBDIR.pri \
    ../../OSBITS.pri \
    ../../useCore.pri

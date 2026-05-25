QT -= gui
QT *= core
QT *= network
TEMPLATE = lib
DEFINES += IRBASE_LIBRARY

include(../libs.pri)

SOURCES += \
    AText.cpp \
    ATextList.cpp \
    CText.cpp \
    CTextList.cpp \
    Enumeration.cpp \
    FSText.cpp \
    FSTextList.cpp \
    Key.cpp \
    KeySeg.cpp \
    KeySegList.cpp \
    MillisecondTime.cpp \
    Null.cpp \
    Severity.cpp \
    TriBool.cpp \
    UText.cpp \
    Uid.cpp \
    VersionInfo.cpp \
    XText.cpp \
    irBase.cpp

HEADERS += \
    ../../version.h \
    AText.h \
    ATextList.h \
    CText.h \
    CTextList.h \
    DualMap.h \
    Enumeration.h \
    FSText.h \
    FSTextList.h \
    Key.h \
    KeySeg.h \
    KeySegList.h \
    List.h \
    MillisecondTime.h \
    Named.h \
    Null.h \
    Severity.h \
    TriBool.h \
    Types.h \
    UText.h \
    Uid.h \
    VersionInfo.h \
    XText.h \
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

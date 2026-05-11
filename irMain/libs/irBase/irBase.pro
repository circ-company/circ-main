QT -= gui
TEMPLATE = lib
DEFINES += IRBASE_LIBRARY
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

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
    KeyVarMap.cpp \
    NAText.cpp \
    Severity.cpp \
    UText.cpp \
    XText.cpp \
    irBase.cpp

HEADERS += \
    ../../version.h \
    AText.h \
    ATextList.h \
    CText.h \
    CTextList.h \
    DataProperty.h \
    DualMap.h \
    Enumeration.h \
    FSText.h \
    FSTextList.h \
    Key.h \
    KeyMap.h \
    KeySeg.h \
    KeySegList.h \
    KeyVarMap.h \
    MetaType.h \
    NAText.h \
    Named.h \
    Severity.h \
    Types.h \
    UText.h \
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
    ../../useCore.pri

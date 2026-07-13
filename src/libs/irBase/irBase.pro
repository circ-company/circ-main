QT *= gui
QT *= core
QT *= network
QT *= testlib

TEMPLATE = lib
DEFINES += IRBASE_LIBRARY

include(../libs.pri)

SOURCES += \
    AText.cpp \
    ATextList.cpp \
    BaseExe.cpp \
    BaseTypeFormat.cpp \
    CText.cpp \
    CTextList.cpp \
    CharType.cpp \
    CodeContext.cpp \
    CppTypeFormat.cpp \
    DirInfo.cpp \
    Enumeration.cpp \
    ExeObject.cpp \
    FSText.cpp \
    FSTextList.cpp \
    FileInfo.cpp \
    FileInfoList.cpp \
    FunctionInfo.cpp \
    Id.cpp \
    Key.cpp \
    KeyList.cpp \
    KeySeg.cpp \
    KeySegList.cpp \
    KeyVarMap.cpp \
    MetaType.cpp \
    MillisecondTime.cpp \
    NanosecondTime.cpp \
    Null.cpp \
    QCoreTypeFormat.cpp \
    QGuiTypeFormat.cpp \
    Status.cpp \
    StatusLevel.cpp \
    StructTM.cpp \
    TriBool.cpp \
    TypeFormat.cpp \
    UText.cpp \
    UTextList.cpp \
    Uid.cpp \
    UidKeyMap.cpp \
    UidList.cpp \
    Url.cpp \
    Utility.cpp \
    VersionInfo.cpp \
    XText.cpp \
    irBase.cpp

HEADERS += \
    ../../version.h \
    AText.h \
    ATextList.h \
    BaseExe.h \
    BaseTypeFormat.h \
    CText.h \
    CTextList.h \
    CharType.h \
    CodeContext.h \
    CppTypeFormat.h \
    DirInfo.h \
    DualMap.h \
    EnumHelper.h \
    Enumeration.h \
    ExeObject.h \
    FSText.h \
    FSTextList.h \
    FileInfo.h \
    FileInfoList.h \
    FunctionInfo.h \
    Id.h \
    Key.h \
    KeyList.h \
    KeyMap.h \
    KeySeg.h \
    KeySegList.h \
    KeyVarMap.h \
    List.h \
    MetaType.h \
    MillisecondTime.h \
    Named.h \
    NanosecondTime.h \
    Null.h \
    QCoreTypeFormat.h \
    QGuiTypeFormat.h \
    Status.h \
    StatusLevel.h \
    StructTM.h \
    TriBool.h \
    TypeFormat.h \
    Types.h \
    UText.h \
    UTextList.h \
    Uid.h \
    UidKeyMap.h \
    UidList.h \
    Url.h \
    Utility.h \
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
    ../../../.gitignore \
    ../../BINDIR.pri \
    ../../BLDCFG.pri \
    ../../CVMAJOR.pri \
    ../../CVVERSION.pri \
    ../../DESTDIR.pri \
    ../../LIBDIR.pri \
    ../../OSBITS.pri \

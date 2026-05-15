QT -= gui
QT *= network
TEMPLATE = lib
DEFINES += IRTYPES_LIBRARY

include(../libs.pri)
include(../../useBase.pri)

SOURCES += \
    ATextList.cpp \
    CodeArgument.cpp \
    CodeArgumentList.cpp \
    CodeContext.cpp \
    FSText.cpp \
    FSTextList.cpp \
    FileInfo.cpp \
    FunctionInfo.cpp \
    GerogianHNanoTime.cpp \
    Id.cpp \
    Key.cpp \
    KeySeg.cpp \
    KeySegList.cpp \
    KeyVarMap.cpp \
    MillisecondTime.cpp \
    NanosecondTime.cpp \
    NetworkMacAddress.cpp \
    Null.cpp \
    RandomGenerator.cpp \
    Result.cpp \
    StatusCode.cpp \
    StructTM.cpp \
    TriBool.cpp \
    UTextList.cpp \
    Uid.cpp \
    UidKeyMap.cpp \
    UidList.cpp \
    XText.cpp \
    irTypes.cpp

HEADERS += \
    ATextList.h \
    CodeArgument.h \
    CodeArgumentList.h \
    CodeContext.h \
    DataProperty.h \
    FSText.h \
    FSTextList.h \
    FileInfo.h \
    FunctionInfo.h \
    GerogianHNanoTime.h \
    Id.h \
    Key.h \
    KeyMap.h \
    KeySeg.h \
    KeySegList.h \
    KeyVarMap.h \
    MetaType.h \
    MillisecondTime.h \
    NanosecondTime.h \
    NetworkMacAddress.h \
    Null.h \
    RandomGenerator.h \
    Result.h \
    StatusCode.h \
    StructTM.h \
    TriBool.h \
    UTextList.h \
    Uid.h \
    UidKeyMap.h \
    UidList.h \
    XText.h \
    irTypes_global.h \
    irTypes.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

QT -= gui
TEMPLATE = lib
DEFINES += IRTYPES_LIBRARY

include(../libs.pri)
include(../../useBase.pri)
include(../../useQCore.pri)
include(../../useQNetwork.pri)

SOURCES += \
    CodeArgument.cpp \
    CodeArgumentList.cpp \
    CodeContext.cpp \
    FunctionInfo.cpp \
    GerogianHNanoTime.cpp \
    Id.cpp \
    KeyVarMap.cpp \
    NanosecondTime.cpp \
    RandomGenerator.cpp \
    Result.cpp \
    StatusCode.cpp \
    StructTM.cpp \
    UTextList.cpp \
    UidKeyMap.cpp \
    UidList.cpp \
    irTypes.cpp

HEADERS += \
    CodeArgument.h \
    CodeArgumentList.h \
    CodeContext.h \
    DataProperty.h \
    FunctionInfo.h \
    GerogianHNanoTime.h \
    Id.h \
    KeyMap.h \
    KeyVarMap.h \
    MetaType.h \
    NanosecondTime.h \
    RandomGenerator.h \
    Result.h \
    StatusCode.h \
    StructTM.h \
    UTextList.h \
    UidKeyMap.h \
    UidList.h \
    irTypes_global.h \
    irTypes.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

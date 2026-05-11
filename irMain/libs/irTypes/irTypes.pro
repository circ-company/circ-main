QT -= gui
TEMPLATE = lib
DEFINES += IRTYPES_LIBRARY

include(../libs.pri)
include(../../useBase.pri)

SOURCES += \
    ATextList.cpp \
    FSText.cpp \
    FSTextList.cpp \
    Key.cpp \
    KeySeg.cpp \
    KeySegList.cpp \
    KeyVarMap.cpp \
    MillisecondTime.cpp \
    NAText.cpp \
    XText.cpp \
    irTypes.cpp

HEADERS += \
    ATextList.h \
    DataProperty.h \
    FSText.h \
    FSTextList.h \
    Key.h \
    KeyMap.h \
    KeySeg.h \
    KeySegList.h \
    KeyVarMap.h \
    MetaType.h \
    MillisecondTime.h \
    NAText.h \
    XText.h \
    irTypes_global.h \
    irTypes.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

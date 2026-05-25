QT *= core
CONFIG += cmdline
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

include(../console.pri)
include(../../useBase.pri)
include(../../useTypes.pri)
include(../../useQCore.pri)

SOURCES += \
        MainConsoleApplication.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    MainConsoleApplication.h

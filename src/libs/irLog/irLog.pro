QT -= gui
TEMPLATE = lib
DEFINES += IRLOG_LIBRARY

include(../libs.pri)
include(../../useBase.pri)
include(../../useTypes.pri)
include(../../useQNetwork.pri)

SOURCES += \
    Log.cpp \
    LogEngine.cpp \
    LogItem.cpp \
    LogMsgType.cpp \
    LogOutput.cpp \
    OutputInterface.cpp \
    OutputPlugin.cpp \
    irLog.cpp

HEADERS += \
    Log.h \
    LogEngine.h \
    LogItem.h \
    LogMacros.h \
    LogMsgType.h \
    LogOutput.h \
    OutputInterface.h \
    OutputPlugin.h \
    irLog_global.h \
    irLog.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

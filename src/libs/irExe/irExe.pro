QT *= core
QT *= gui
QT *= xml
TEMPLATE = lib
DEFINES += IREXE_LIBRARY

include(../libs.pri)

SOURCES += \
    Action.cpp \
    ActionManager.cpp \
    CommandLine.cpp \
    Configuration.cpp \
    ExeSupport.cpp \
    MainOptions.cpp \
    ObjectHelper.cpp \
    Option.cpp \
    Options.cpp \
    Settings.cpp \
    SettingsFile.cpp \
    irExe.cpp

HEADERS += \
    Action.h \
    ActionManager.h \
    CommandLine.h \
    Configuration.h \
    ExeSupport.h \
    MainOptions.h \
    ObjectHelper.h \
    Option.h \
    Options.h \
    Settings.h \
    SettingsFile.h \
    irExe_global.h \
    irExe.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

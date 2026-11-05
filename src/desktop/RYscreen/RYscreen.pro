QT *= core
QT *= gui
QT *= widgets

include(../desktop.pri)
include(../../useLog.pri)
include(../../useTypes.pri)
include(../../useCore.pri)
include(../../useColor.pri)
include(../../useQWidgets.pri)
include(../../useRyWidgets.pri)

SOURCES += \
    RYApplication.cpp \
    main.cpp \
    RYMainWindow.cpp \

HEADERS += \
    RYApplication.h \
    RYMainWindow.h \

message(INCLUDEPATH == $$INCLUDEPATH)

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

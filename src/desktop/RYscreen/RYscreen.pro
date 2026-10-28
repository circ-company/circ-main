QT *= core
QT *= gui
QT *= widgets

include(../desktop.pri)
include(../../useQWidgets.pri)

SOURCES += \
    RYApplication.cpp \
    main.cpp \
    RYMainWindow.cpp

HEADERS += \
    RYApplication.h \
    RYMainWindow.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

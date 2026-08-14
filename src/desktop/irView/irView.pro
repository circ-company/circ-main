QT *= core
QT *= gui
QT *= widgets
QT *= xml

include(../desktop.pri)
include(../../useBase.pri)
include(../../useLog.pri)
include(../../useMatGeo.pri)
include(../../useStore.pri)
include(../../useTypes.pri)
include(../../useExe.pri)
include(../../useQXml.pri)
include(../../useQGui.pri)
include(../../useQWidgets.pri)
include(../../useImage.pri)

SOURCES += \
    irViewApplication.cpp \
    main.cpp \
    irViewMainWindow.cpp

HEADERS += \
    irViewApplication.h \
    irViewMainWindow.h

FORMS += \
    irViewMainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

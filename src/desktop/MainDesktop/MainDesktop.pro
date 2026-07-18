QT *= core
QT *= gui
QT *= widgets
QT *= xml

include(../desktop.pri)
include(../../useBase.pri)
include(../../useLog.pri)
include(../../useMatGeo.pri)
include(../../useQNetwork.pri)
include(../../useQCore.pri)
include(../../useStore.pri)
include(../../useTypes.pri)
include(../../useExe.pri)
include(../../useQXml.pri)
include(../../useQGui.pri)
include(../../useQWidgets.pri)
include(../../useImage.pri)
include(../../useCVCore.pri)
include(../../useCVobjdetect.pri)
include(../../QtCVobjdetect.pri)

SOURCES += \
    Application.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    ../../version.h \
    Application.h \
    MainWindow.h \
    version.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


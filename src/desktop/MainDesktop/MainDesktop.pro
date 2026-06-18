QT *= core
QT *= gui
QT *= widgets

include("../desktop.pri")
include("../../useBase.pri")
include("../../useMatGeo.pri")
include("../../useCVCore.pri")
include("../../useQNetwork.pri")
include("../../useQCore.pri")
include("../../useTypes.pri")
include("../../useLog.pri")
include("../../useQGui.pri")
include("../../useQWidgets.pri")
include("../../useStore.pri")
include("../../useImage.pri")

SOURCES += \
    Application.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    Application.h \
    MainWindow.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


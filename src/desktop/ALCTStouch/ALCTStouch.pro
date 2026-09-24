QT *= core
QT *= gui
QT *= widgets
QT *= statemachine

include(../../version.pri)
include(../desktop.pri)
include(../../useBase.pri)
include(../../useLog.pri)
include(../../useMatGeo.pri)
include(../../useTypes.pri)
include(../../useQCore.pri)
include(../../useStore.pri)
include(../../useQXml.pri)
include(../../useQGui.pri)
include(../../useColor.pri)
include(../../useQWidgets.pri)
include(../../useImage.pri)
include(../../useTouch.pri)

SOURCES += \
    ATApplication.cpp \
    ATMainWindow.cpp \
    main.cpp

HEADERS += \
    ATApplication.h \
    ATMainWindow.h \
    version.h

TRANSLATIONS += \
    ALCTStouch_en_JP.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

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
    BaseLoyaltyDisplayPage.cpp \
    BlankPage.cpp \
    HomePage.cpp \
    LoyaltyDisplayBackend.cpp \
    LoyaltyDisplayScreen.cpp \
    NormalFaceLayoutWidget.cpp \
    main.cpp

HEADERS += \
    BaseLoyaltyDisplayPage.h \
    BlankPage.h \
    HomePage.h \
    LoyaltyDisplayBackend.h \
    LoyaltyDisplayScreen.h \
    NormalFaceLayoutWidget.h \
    version.h

TRANSLATIONS += \
    LoyaltyDisplay_en_US.ts

CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

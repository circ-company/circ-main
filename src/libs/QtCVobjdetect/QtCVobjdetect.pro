# {QtCV}/QtCVobjdetect.pro

QT += gui
QT += xml
TEMPLATE = lib
DEFINES += QTCVOBJDETECT_LIBRARY

include(../libs.pri)
include(../../useBase.pri)
include(../../useLog.pri)

SOURCES += \
    QtCVobjdetect.cpp \
    cvODCatalog.cpp \
    cvODCatalogEntry.cpp \
    cvODClass.cpp \
    cvODResource.cpp \
    cvODResourceBase.cpp \
    cvODResourceCascade.cpp \
    cvODType.cpp \
    cvObjDetect.cpp \

HEADERS += \
    QtCVobjdetect_global.h \
    QtCVobjdetect.h \
    cvODCatalog.h \
    cvODCatalogEntry.h \
    cvODClass.h \
    cvODResource.h \
    cvODResourceBase.h \
    cvODResourceCascade.h \
    cvODType.h \
    cvObjDetect.h \


# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../../usr/lib/x86_64-linux-gnu/ -lopencv_objdetect
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../../usr/lib/x86_64-linux-gnu/ -lopencv_objdetectd
else:unix:!macx: LIBS += -L$$PWD/../../../../../../../usr/lib/x86_64-linux-gnu/ -lopencv_objdetect

INCLUDEPATH += $$PWD/../../../../../../../usr/include/opencv4
DEPENDPATH += $$PWD/../../../../../../../usr/include/opencv4

DISTFILES += \
    ../../../../opencv/data/haarcascades/haarcascade_eye.xml \
    ../../../../opencv/data/haarcascades/haarcascade_eye_tree_eyeglasses.xml \
    ../../../../opencv/data/haarcascades/haarcascade_frontalcatface.xml \
    ../../../../opencv/data/haarcascades/haarcascade_frontalcatface_extended.xml \
    ../../../../opencv/data/haarcascades/haarcascade_frontalface_alt.xml \
    ../../../../opencv/data/haarcascades/haarcascade_frontalface_alt2.xml \
    ../../../../opencv/data/haarcascades/haarcascade_frontalface_alt_tree.xml \
    ../../../../opencv/data/haarcascades/haarcascade_frontalface_default.xml \
    ../../../../opencv/data/haarcascades/haarcascade_fullbody.xml \
    ../../../../opencv/data/haarcascades/haarcascade_lefteye_2splits.xml \
    ../../../../opencv/data/haarcascades/haarcascade_license_plate_rus_16stages.xml \
    ../../../../opencv/data/haarcascades/haarcascade_lowerbody.xml \
    ../../../../opencv/data/haarcascades/haarcascade_profileface.xml \
    ../../../../opencv/data/haarcascades/haarcascade_righteye_2splits.xml \
    ../../../../opencv/data/haarcascades/haarcascade_russian_plate_number.xml \
    ../../../../opencv/data/haarcascades/haarcascade_smile.xml \
    ../../../../opencv/data/haarcascades/haarcascade_upperbody.xml

QT *= core
QT -= gui
TEMPLATE = lib
DEFINES += IRMSG_LIBRARY

include(../libs.pri)
include(../../useBase.pri)
include(../../useLog.pri)

SOURCES += \
    BaseMessageTransport.cpp \
    Message.cpp \
    MessageAttachment.cpp \
    MessageBody.cpp \
    MessageCenter.cpp \
    MessageEncoding.cpp \
    MessageHeader.cpp \
    Messenger.cpp \
    irMsg.cpp

HEADERS += \
    BaseMessageTransport.h \
    Message.h \
    MessageAttachment.h \
    MessageBody.h \
    MessageCenter.h \
    MessageEncoding.h \
    MessageHeader.h \
    Messenger.h \
    irMsg_global.h \
    irMsg.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

# {circ-code}/src/useMsg.pri
include(LIBDIR.pri)
include(DESTDIR.pri)

INCLUDEPATH *= $$LIBDIR/irMsg
INCLUDEPATH *= $$LIBDIR/../../src/libs/irMsg
windows:LIBS *= -lirMsg6
linux:LIBS *= -lirMsg
LIBS *= -L$$DESTDIR
#message(--------/src/useMsg.pri LIBS=$$LIBS DESTDIR==$$DESTDIR LIBDIR==$$LIBDIR INCLUDEPATH==$$INCLUDEPATH )

HEADERS +=



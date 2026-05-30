# {ottoZcode}/src/useLog.pri
include(LIBDIR.pri)
include(DESTDIR.pri)

INCLUDEPATH *= $$LIBDIR/irBase $$LIBDIR/irLog
INCLUDEPATH *= $$LIBDIR/../../src/libs/irLog
windows:LIBS *= -lirLog6
linux:LIBS *= -lirLog
LIBS *= -L$$DESTDIR
#message(--------/src/useType.pri LIBS=$$LIBS DESTDIR==$$DESTDIR LIBDIR==$$LIBDIR INCLUDEPATH==$$INCLUDEPATH )

HEADERS +=



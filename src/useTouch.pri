# {ottoZcode}/src/useTouch.pri
include(LIBDIR.pri)
include(DESTDIR.pri)

INCLUDEPATH *= $$LIBDIR/irBase $$LIBDIR/irTouch
INCLUDEPATH *= $$LIBDIR/../../src/libs/irTouch
windows:LIBS *= -lirTouch6
linux:LIBS *= -lirTouch
LIBS *= -L$$DESTDIR
#message(--------/src/useType.pri LIBS=$$LIBS DESTDIR==$$DESTDIR LIBDIR==$$LIBDIR INCLUDEPATH==$$INCLUDEPATH )

HEADERS +=



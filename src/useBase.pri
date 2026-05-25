# {circ-code}/src/useBase.pri
include(LIBDIR.pri)
include(DESTDIR.pri)

INCLUDEPATH *= $$LIBDIR/irBase
INCLUDEPATH *= $$LIBDIR/../../src/libs/irBase
windows:LIBS *= -lirBase6
linux:LIBS *= -lirBase
LIBS *= -L$$DESTDIR
#message(--------/src/useBase.pri LIBS=$$LIBS DESTDIR==$$DESTDIR LIBDIR==$$LIBDIR INCLUDEPATH==$$INCLUDEPATH )

HEADERS +=



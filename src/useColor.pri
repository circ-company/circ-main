# {circ-main}/src/useColor.pri
include(LIBDIR.pri)
include(DESTDIR.pri)

INCLUDEPATH *= $$LIBDIR/irColor
INCLUDEPATH *= $$LIBDIR/../../src/libs/irColor
windows:LIBS *= -lirColor6
linux:LIBS *= -lirColor
LIBS *= -L$$DESTDIR

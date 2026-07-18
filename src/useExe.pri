# {irMain}/src/useExe.pri
include(LIBDIR.pri)
include(DESTDIR.pri)

INCLUDEPATH *= $$LIBDIR/irBase $$LIBDIR/irExe
INCLUDEPATH *= $$LIBDIR/../../src/libs/irExe
windows:LIBS *= -lirExe6
linux:LIBS *= -lirExe
LIBS *= -L$$DESTDIR

HEADERS +=



# {circ-code}/src/useQGui.pri
include(LIBDIR.pri)
include(DESTDIR.pri)

INCLUDEPATH *= $$LIBDIR/irqGui
INCLUDEPATH *= $$LIBDIR/../../src/libs/irqGui
windows:LIBS *= -lirqGui6
linux:LIBS *= -lirqGui
LIBS *= -L$$DESTDIR
#message(--------/src/useBase.pri LIBS=$$LIBS DESTDIR==$$DESTDIR LIBDIR==$$LIBDIR INCLUDEPATH==$$INCLUDEPATH )

HEADERS +=



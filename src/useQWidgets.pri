# {circ-code}/src/useQWidgets.pri
include(LIBDIR.pri)
include(DESTDIR.pri)

INCLUDEPATH *= $$LIBDIR/irqWidgets
INCLUDEPATH *= $$LIBDIR/../../src/libs/irqWidgets
windows:LIBS *= -lirqWidgets6
linux:LIBS *= -lirqWidgets
LIBS *= -L$$DESTDIR
#message(--------/src/useBase.pri LIBS=$$LIBS DESTDIR==$$DESTDIR LIBDIR==$$LIBDIR INCLUDEPATH==$$INCLUDEPATH )

HEADERS +=



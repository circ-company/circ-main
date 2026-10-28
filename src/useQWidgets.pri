# {circ-code}/src/useQWidgets.pri
include(LIBDIR.pri)
include(DESTDIR.pri)

include(useBase.pri)
include(useMatGeo.pri)

INCLUDEPATH *= $$LIBDIR/irqWidgets
#NCLUDEPATH *= $$LIBDIR/../../src/libs/irqWidgets
windows:LIBS *= -lirqWidgets6
linux:LIBS *= -lirqWidgets
LIBS *= -L$$DESTDIR
#message(--------/src/useBase.pri LIBS=$$LIBS DESTDIR==$$DESTDIR LIBDIR==$$LIBDIR INCLUDEPATH==$$INCLUDEPATH )

HEADERS +=



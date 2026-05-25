# {circ-code}/src/useQNetwork.pri
include(LIBDIR.pri)
include(DESTDIR.pri)

INCLUDEPATH *= $$LIBDIR/irqNetwork
INCLUDEPATH *= $$LIBDIR/../../src/libs/irqNetwork
windows:LIBS *= -lirqNetwork6
linux:LIBS *= -lirqNetwork
QT *= network
LIBS *= -L$$DESTDIR
#message(--------/src/useBase.pri LIBS=$$LIBS DESTDIR==$$DESTDIR LIBDIR==$$LIBDIR INCLUDEPATH==$$INCLUDEPATH )

HEADERS +=



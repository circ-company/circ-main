# {circ-main}/src/useQXml.pri
include(LIBDIR.pri)
include(DESTDIR.pri)

INCLUDEPATH *= $$LIBDIR/irBase $$LIBDIR/irqXml
INCLUDEPATH *= $$LIBDIR/../../src/libs/irqXml
windows:LIBS *= -lirqXml6
linux:LIBS *= -lirqXml
LIBS *= -L$$DESTDIR
QT *= xml
HEADERS +=



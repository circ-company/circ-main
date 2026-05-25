# {ottoZcode}/src/useMatGeo.pri
include(LIBDIR.pri)
include(DESTDIR.pri)

INCLUDEPATH *= $$LIBDIR/irBase $$LIBDIR/irMatGeo
windows:LIBS *= -lirMatGeo6
linux:LIBS *= -lirMatGeo
LIBS *= -L$$DESTDIR
#message(--------/src/useType.pri LIBS=$$LIBS DESTDIR==$$DESTDIR LIBDIR==$$LIBDIR INCLUDEPATH==$$INCLUDEPATH )

HEADERS +=



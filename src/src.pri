# {circ-main}/src/src.pri
#message(^^^^^^^^/src/src.pri)

include(version.pri)
include(DESTDIR.pri)
CONFIG += c++23
INCLUDEPATH *= .. . $$LIBDIR/..
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000
#message(VER_MAJ = $$VER_MAJ)
#message(DESTDIR = $$DESTDIR)

DEFINES *= __CIRC__WARN_IS_ERROR
DEFINES *= __CIRC__ERROR_IS_FAULT
DEFINES *= __MAINDESK__IGNORE_CATALOG_NOTEXIST



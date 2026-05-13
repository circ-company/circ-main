# {Eclipse7}/src/src.pri
#message(^^^^^^^^/src/src.pri)

include(version.pri)
include(DESTDIR.pri)
CONFIG += c++23
INCLUDEPATH *= .. . $$LIBDIR/..
QMAKE_CXXFLAGS_DEBUG *= -fdiagnostics-show-option
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000
#message(VER_MAJ = $$VER_MAJ)
#message(DESTDIR = $$DESTDIR)

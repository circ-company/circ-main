# {Eclipse7}/src/src.pri
#message(^^^^^^^^/src/src.pri)

include(version.pri)
include(DESTDIR.pri)
CONFIG += c++23
INCLUDEPATH *= .. .
QMAKE_CXXFLAGS_DEBUG *= -fdiagnostics-show-option
#message(VER_MAJ = $$VER_MAJ)
#message(DESTDIR = $$DESTDIR)

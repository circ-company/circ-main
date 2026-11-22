# {circ-main}/src/desktop/desktop.pri
#message(____________/desktop/desktop.pri)

DEFINES *= __CIRC__WARN_IS_ERROR
DEFINES *= __CIRC__ERROR_IS_FAULT

RSRCDIR = "../.."
RLIBDIR = "../../libs/"
include(../INCIRLIBS.pri)
include(../INCRYLIBS.pri)

include(../DESTDIR.pri)

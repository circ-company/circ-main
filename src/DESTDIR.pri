# {circ-main}/src/DESTDIR.pri

OURDEST = "{bindir}/{bldcfg}{osbits}-Qt{qtver}CV{cvver}-{ver}"

include(BINDIR.pri)
include(BLDCFG.pri)
include(OSBITS.pri)
include(CVMAJOR.pri)

OURDEST = $$replace(OURDEST, "{bindir}", $$BINDIR)
OURDEST = $$replace(OURDEST, "{bldcfg}", $$BLDCFG)
OURDEST = $$replace(OURDEST, "{osbits}", $$OSBITS)
OURDEST = $$replace(OURDEST, "{qtver}", $$QT_MAJOR_VERSION)
OURDEST = $$replace(OURDEST, "{cvver}", $$CVMAJOR)
OURDEST = $$replace(OURDEST, "{ver}", $$VER_STRING)

DESTDIR = $$OURDEST
QMAKE_RPATHDIR = $$OURDEST

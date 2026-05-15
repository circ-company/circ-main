# {ottoZcode}/src/version.pri
#message(------------/src/version.pri)

IRVER_MAJOR        = 6
IRVER_MINOR        = 5
IRVER_RELEASE      = 2
IRVER_BRANCH       = 0
IRVER_STRING       = "v6.05B"
IRVER_COMPANY      = "California Intermountain Research Center"
IRVER_ORGNAME      = "CIRC"
IRVER_COPYRIGHT    = "Copyright (c) 1993-2026, Anthony Otto DBA CIRC Company. All rights reserved worldwide. See LEGAL.txt for more information."
IRVER_PRODUCT      = "CIRCmain"
IRVER_TRADEMARKS   = "California Intermountain Research Center(tm) and CIRC(tm) are trademarks of Anthony Otto. All other marks are property their owners. See LEGAL.txt for more information."
IRVER_COMMENT      = "Contact circ.co.ca@gmail.com for more information."
VER_MAJ = $$IRVER_MAJOR
VER_MIN = $$IRVER_MINOR
VER_PAT = $$IRVER_BRANCH
VER_STRING = $$IRVER_STRING
VERSION = $$IRVER_MAJOR $$IRVER_MINOR $$IRVER_BRANCH $$IRVER_RELEASE
QMAKE_TARGET_COMPANY = $$IRVER_COMPANY
QMAKE_TARGET_COPYRIGHT = $$IRVER_COPYRIGHT
QMAKE_TARGET_PRODUCT = $$IRVER_PRODUCT
QMAKE_TARGET_DESCRIPTION = $$IRVER_PRODUCT

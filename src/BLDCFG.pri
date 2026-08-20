# {Eclipse6}/src/BLDCFG.pri
CONFIG(release, debug|release|profile):BLDCFG = "Rel"
CONFIG(debug,   debug|release|profile):BLDCFG = "Dbg"
CONFIG(profile, debug|release|profile):BLDCFG = "Prf"



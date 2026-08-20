TEMPLATE = subdirs

SUBDIRS += \
    console \
    desktop \
    guicon \
    libs \
    testlibs

# Name of your doc target
doxygen_docs.commands = doxygen $$PWD/libs.qdocconf
doxygen_docs.depends = FORCE

# Add to qmake's install phase or build targets
INSTALLS += doxygen_docs

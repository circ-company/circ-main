TEMPLATE = subdirs

SUBDIRS += \
    console \
    desktop \
    guicon \
    libs \
    testlibs

# Name of your doc target
qdoc_docs.commands = qdoc $$PWD/libs.qdocconf
qdoc_docs.depends = FORCE

# Add to qmake's install phase or build targets
INSTALLS += qdoc_docs

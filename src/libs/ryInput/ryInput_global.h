#pragma once

#include <QtCore/qglobal.h>

#if defined(RYINPUT_LIBRARY)
#define RYINPUT_EXPORT Q_DECL_EXPORT
#else
#define RYINPUT_EXPORT Q_DECL_IMPORT
#endif

#pragma once

#include <QtCore/qglobal.h>

#if defined(RYBASE_LIBRARY)
#define RYBASE_EXPORT Q_DECL_EXPORT
#else
#define RYBASE_EXPORT Q_DECL_IMPORT
#endif

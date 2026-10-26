#pragma once

#include <QtCore/qglobal.h>

#if defined(IFBASE_LIBRARY)
#define IFBASE_EXPORT Q_DECL_EXPORT
#else
#define IFBASE_EXPORT Q_DECL_IMPORT
#endif

#pragma once

#include <QtCore/qglobal.h>

#if defined(IFMATCH_LIBRARY)
#define IFMATCH_EXPORT Q_DECL_EXPORT
#else
#define IFMATCH_EXPORT Q_DECL_IMPORT
#endif

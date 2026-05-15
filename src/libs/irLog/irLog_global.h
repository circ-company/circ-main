#pragma once

#include <QtCore/qglobal.h>

#if defined(IRLOG_LIBRARY)
#define IRLOG_EXPORT Q_DECL_EXPORT
#else
#define IRLOG_EXPORT Q_DECL_IMPORT
#endif

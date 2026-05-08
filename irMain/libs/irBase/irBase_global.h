#pragma once

#include <QtCore/qglobal.h>

#if defined(IRBASE_LIBRARY)
#define IRBASE_EXPORT Q_DECL_EXPORT
#else
#define IRBASE_EXPORT Q_DECL_IMPORT
#endif

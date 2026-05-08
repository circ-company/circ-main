#pragma once

#include <QtCore/qglobal.h>

#if defined(IRQSQL_LIBRARY)
#define IRQSQL_EXPORT Q_DECL_EXPORT
#else
#define IRQSQL_EXPORT Q_DECL_IMPORT
#endif

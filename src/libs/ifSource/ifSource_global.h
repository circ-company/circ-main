#pragma once

#include <QtCore/qglobal.h>

#if defined(IFSOURCE_LIBRARY)
#define IFSOURCE_EXPORT Q_DECL_EXPORT
#else
#define IFSOURCE_EXPORT Q_DECL_IMPORT
#endif

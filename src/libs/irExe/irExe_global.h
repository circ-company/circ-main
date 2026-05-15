#pragma once

#include <QtCore/qglobal.h>

#if defined(IREXE_LIBRARY)
#define IREXE_EXPORT Q_DECL_EXPORT
#else
#define IREXE_EXPORT Q_DECL_IMPORT
#endif

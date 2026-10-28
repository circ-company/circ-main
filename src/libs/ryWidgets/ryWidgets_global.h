#pragma once

#include <QtCore/qglobal.h>

#if defined(RYWIDGETS_LIBRARY)
#define RYWIDGETS_EXPORT Q_DECL_EXPORT
#else
#define RYWIDGETS_EXPORT Q_DECL_IMPORT
#endif

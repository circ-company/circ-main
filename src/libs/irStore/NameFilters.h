#pragma once

#include <QMetaType>
#include <QString>
#include <QStringList>

class NameFilters
{
public:
    void setExtensions(const QString &exts);
    QStringList filterList() const;

private:
    QStringList mFilterList;

public: // QMetaType
    NameFilters() = default;
    ~NameFilters() = default;
    NameFilters(const NameFilters &) = default;
    NameFilters &operator=(const NameFilters &) = default;
    NameFilters & it() { return *this; }
    const NameFilters & it() const { return *this; }
};

inline QStringList NameFilters::filterList() const { return mFilterList; }

Q_DECLARE_METATYPE(NameFilters);

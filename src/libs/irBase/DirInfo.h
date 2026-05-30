#pragma once

#include <QDir>
#include "Null.h"

#include <QMetaType>

#include <Types.h>

#include "FSText.h"
#include "FSTextList.h"

class DirInfo : public QDir, Null
{
public: // types

public: // ctors
    DirInfo(const FSText &path);
    DirInfo(const QDir &other);

public: // const
    bool isEmpty() const;
    bool isValidIndex(const Index ix) const;
    Count count() const;
    FSText at(const Index ix) const;
    FSTextList first(const Count k) const;

public: // non-const
    void clear();
    void set();
    void setTo(const FSText &fstx);
    void setTo(const QDir &other);

public: // pointers

private:
    FSTextList mDirNames;

public: // QMetaType
    DirInfo() = default;
    ~DirInfo() = default;
    DirInfo(const DirInfo &) = default;
    DirInfo &operator=(const DirInfo &) = default;
};

inline bool DirInfo::isEmpty() const { return mDirNames.isEmpty(); }
inline Count DirInfo::count() const { return mDirNames.count(); }
inline FSText DirInfo::at(const Index ix) const { return mDirNames.at(ix); }

Q_DECLARE_METATYPE(DirInfo);


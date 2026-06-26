#pragma once

#include <QFileInfo>
#include "Null.h"


#include <QDir>
#include <QMetaType>
#include <QString>
#include <QVariant>

#include "FSText.h"
#include "FSTextList.h"

class FileInfo : public QFileInfo, public Null
{
public: // types
    typedef QList<FileInfo> List;
    enum StringOption
    {
        $null               = 0,
        Drive               = 0x80000000,
        AbsolutePath        = 0x40000000,
        AllPath             = 0x20000000,
        FirstPath           = 0x10000000,
        Elipses             = 0x08000000,
        LastPath            = 0x04000000,
        BaseName            = 0X00800000,
        CompleteBaseName    = 0x00400000,
        SuffixDot           = 0x00200000,
        Suffix              = 0x00100000,
        Exists              = 0x00008000,
        Readable            = 0x00004000,
        Writable            = 0x00002000,
        Executable          = 0x00001000,
        Dir                 = 0x00000800,
        File                = 0x00000400,
        Hidden              = 0x00000200,
        Root                = 0x00000100,
        Absolute            = 0x00000080,
        Alias               = 0x00000040,
        Bundle              = 0x00000020,
        Junction            = 0x00000010,
        Native              = 0x00000008,
        Other               = 0x00000004,
        SymLink             = 0x00000002,
        Symbolic            = 0x00000001
    };
    Q_DECLARE_FLAGS(StringOptions, StringOption);

public: // ctors
    FileInfo(const QFileInfo &other);
    FileInfo(const FSText &filePathName);
    FileInfo(const QDir &dir, const QString &fileName);

public: // const
    bool exists() const;
    FSText dirFirst(const qsizetype k) const;
    FSText dirFirst(const qsizetype k, const char ch) const;
    FSText dirLast() const;
    QString toString(const StringOptions aOptions) const;
    QVariant toVariant() const;

public: // non-const
    void clear();

private: // non-const
    void setDirs();

private:
    FSTextList mDirNames;

public: // QMetaType
    FileInfo & it() { return *this; }
    const FileInfo & it() const { return *this; }
    FileInfo() = default;
    ~FileInfo() = default;
    FileInfo(const FileInfo &) = default;
    FileInfo &operator=(const FileInfo &) = default;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(FileInfo::StringOptions);
Q_DECLARE_METATYPE(FileInfo);


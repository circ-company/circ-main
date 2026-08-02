#pragma once

#include <QFileInfo>
#include "Null.h"

#include <QDir>
#include <QMetaType>
#include <QString>
#include <QStringList>
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
        NullFull            = 0x00008000,
        Exists              = 0x00004000,
        Readable            = 0x00002000,
        Writable            = 0x00001000,
        Executable          = 0x00000800,
        Dir                 = 0x00000400,
        File                = 0x00000200,
        Hidden              = 0x00000100,
        Root                = 0x00000080,
        Absolute            = 0x00000040,
        Alias               = 0x00000020,
        Junction            = 0x00000010,
        Native              = 0x00000008,
        SymLink             = 0x00000004,
        Symbolic            = 0x00000002,
        Negatives           = 0x00000001,
        ElipsesPath         = FirstPath | Elipses | LastPath,
        FileName            = CompleteBaseName | SuffixDot | Suffix,
        AllFilePath         = AllPath | FileName,
        BasicFilePath       = ElipsesPath | FileName,
        Status              = NullFull | Exists | Readable | Writable | Executable,
        Characteristics     = Dir | File | Hidden | Root,
        Flags               = Absolute | Alias | Junction | Native
                                | SymLink | Symbolic,
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
    QFileInfo toQFileInfo() const;
    QString toString(const StringOptions aOptions
                     =StringOptions(BasicFilePath | Status)) const;
    QStringList toStringList(const StringOptions aOptions=StringOptions(0)) const;
    QVariant toVariant() const;
    operator QVariant () const;

public: // non-const
    void clear();

private: // const
    QString attributeFlags() const;
    QString statusFlags() const;

private: // non-const
    void setup();

private: // static
    static QString stringOption(const StringOption aOpt);

private:
    FSTextList mDirNames;
    StringOptions mOptions;

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

inline FileInfo::operator QVariant() const { return toVariant(); }

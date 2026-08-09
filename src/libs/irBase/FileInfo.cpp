#include "FileInfo.h"

FileInfo::FileInfo(const QFileInfo &other)
    : QFileInfo(other), Null(false) { setup(); }
FileInfo::FileInfo(const FSText &filePathName)
    : QFileInfo(filePathName), Null(false) { setup(); }
FileInfo::FileInfo(const QDir &dir, const QString &fileName)
    : QFileInfo(dir, fileName), Null(false) { setup(); }

bool FileInfo::exists() const
{
    return full() ? QFileInfo::exists() : false;
}

FSText FileInfo::dirFirst(const qsizetype k) const
{
    return dirFirst(k, '/');
}

FSText FileInfo::dirFirst(const qsizetype k, const char ch) const
{
    FSTextList tOldList(mDirNames), tNewList;
    while (tNewList.count() < k)
        tNewList.append(tOldList.takeFirst());
    return tNewList.join(ch);
}

FSText FileInfo::dirLast() const
{
    return mDirNames.constLast();
}

QFileInfo FileInfo::toQFileInfo() const
{
    return *(QFileInfo *)&(it());
}

QVariant FileInfo::toVariant() const
{
    QVariant result;
    if (full()) result.setValue<QFileInfo>(toQFileInfo());
    return result;
}

QString FileInfo::toString(const StringOptions aOptions) const
{
    QString result;
    if (null())
    {
        result = "{NULL}";
        return result;                                          /*/=====\*/
    }
    if (aOptions.testFlag(CompleteBaseName))
        result.append(" " + completeBaseName() + " ");
    if (aOptions.testFlag(NullFull))
        result.append(" " + QString(full()
                                        ? "Full"
                                        : (aOptions.testFlag(Negatives)
                                               ? "NULL"
                                               : "")) + " ");
    if (aOptions.testFlag(Readable))
        result.append(" " + QString(isReadable()
                                 ? "Readable"
                                 : (aOptions.testFlag(Negatives)
                                        ? "NOT Readable"
                                        : "")) + " ");
    if (aOptions.testFlag(ElipsesPath))
    {
        if (mDirNames.count() > 2)
            result = dirFirst(1) + FSText("/.../") + dirLast();
        else
            result = mDirNames.join('/');
    }
    return result;
}

QStringList FileInfo::toStringList(const StringOptions aOptions) const
{
    Q_UNUSED(aOptions); // TODO use aOptions
    QStringList result;
    if (null())
    {
        result << QString("{FileInfo: <null>}");
        return result;
    }
    result << QString("{FileInfo:               %1").arg(toString(FileName));
    result << QString("---AbsolutePath:         %1").arg(toString(AbsolutePath));
    result << QString("---Creation:             %1").arg(fileTime(QFileDevice::FileBirthTime).toString("DyyyyMMdd-Thhmmsszzz"));
    result << QString("---Modified:             %1").arg(fileTime(QFileDevice::FileModificationTime).toString("DyyyyMMdd-Thhmmsszzz"));
    result << QString("---MetaData:             %1").arg(fileTime(QFileDevice::FileMetadataChangeTime).toString("DyyyyMMdd-Thhmmsszzz"));
    result << QString("---Accessed:             %1").arg(fileTime(QFileDevice::FileAccessTime).toString("DyyyyMMdd-Thhmmsszzz"));
    result << QString("---Attributes:           %1").arg(attributeFlags());
    result << QString("---Status:               %1}").arg(statusFlags());
    return result;
}

void FileInfo::clear()
{
    QFileInfo::setFile("");
    Null::nullify();
}

QString FileInfo::attributeFlags() const
{
    QStringList results;
    if (mOptions.testFlag(Exists))          results << "Exists";
    if (mOptions.testFlag(Readable))        results << "Readable";
    if (mOptions.testFlag(Writable))        results << "Writable";
    if (mOptions.testFlag(Executable))      results << "Executable";
    return results.join(' ');
}

QString FileInfo::statusFlags() const
{
    QStringList results;
    if (null())                             results << "Null";
    if (mOptions.testFlag(Dir))             results << "Dir";
    if (mOptions.testFlag(File))            results << "File";
    if (mOptions.testFlag(Hidden))          results << "Hidden";
    if (mOptions.testFlag(Root))            results << "Root";
    if (mOptions.testFlag(Absolute))        results << "Absolute";
    return results.join(' ');
}

void FileInfo::setup()
{
    FSText tDirNameText = dir().path();
    mDirNames = tDirNameText.split('/');
    if (exists())           mOptions.setFlag(Exists);
    if (isReadable())       mOptions.setFlag(Readable);
    if (isWritable())       mOptions.setFlag(Writable);
    if (isExecutable())     mOptions.setFlag(Executable);
    if (isFile())           mOptions.setFlag(File);
    if (isDir())            mOptions.setFlag(Dir);
    if (isHidden())         mOptions.setFlag(Hidden);
    if (isRoot())           mOptions.setFlag(Root);
    if (isAbsolute())       mOptions.setFlag(Absolute);

}


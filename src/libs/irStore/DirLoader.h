#pragma once

#include <QObject>

#include <QDir>
#include <QModelIndex>
#include <QStringList>
class QFileSystemModel;
class QTimer;

#include <AText.h>
#include <List.h>
#include <FileInfo.h>
#include <FileInfoList.h>
#include <FSText.h>

class DirLoader : public QObject
{
    Q_OBJECT
public: // types
    enum StartOption
    {
        $null       = 0,
        Collect     = 0x00000001,
        SubDirs     = 0x00000002,
        Watch       = 0x00000004,
    };
    Q_DECLARE_FLAGS(StartOptions, StartOption)
    Q_FLAG(StartOptions)

    typedef ListT<QDir> QDirList;

public: // ctors
    explicit DirLoader(QObject *parent = nullptr);
    DirLoader(const FSText &dirName, QObject *parent = nullptr);
    DirLoader(const QDir &dir, QObject *parent = nullptr);

public slots:
    void initialize(const StartOptions opts=DirLoader::StartOption::$null);
    void start(const StartOptions opts=DirLoader::StartOption::$null);
    void start(const FSText &dirName, const DirLoader::StartOptions opts);
    void start(const QDir &dir, const DirLoader::StartOptions opts);
    void dirIsLoaded(const QString &path);
    void processDir(const QDir &dir, const DirLoader::StartOptions opts);
    void pulse();
    void processDir(const FileInfo fileInfo);
    void processFile(const FileInfo fileInfo);

signals:
    void started(const FSText dirName);
    void empty(const FSText dirName);
    void dirFinished(const FSText dirName);
    void file(const FileInfo fileInfo);
    void dir(const FileInfo fileInfo);

public: // const
    FSText basePath() const;
    QDir baseDir() const;

public: // non-const
    void set(const FSText &dirName);
    void set(const QDir &dir);
    void setFilter(QDir::Filters filters);
    void setNameFilters(const QStringList &nameFilters);
    void setNameFilters(const FSText &suffixNames);

public: // pointers
    QFileSystemModel * model();

public: // debug
    QStringList toDebugStrings() const;

private:
    Milliseconds mPulseMsec=500;
    QDir mBaseDir;
    QDirList mSubDirList;
    QFileSystemModel * mpModel;
    QTimer * mpPulseTimer;
    bool mDirLoaded=false;
    QDir mCurrentDir;
    QModelIndex mParentIndex;
    QModelIndex mCurrentIndex;
    int mCurrentRow=0;
    StartOptions mCurrentOptions;
    FileInfoList mCurrentFiles;
};

inline FSText DirLoader::basePath() const { return baseDir().path(); }
inline QDir DirLoader::baseDir() const { return mBaseDir; }
inline QFileSystemModel *DirLoader::model() { Q_CHECK_PTR(mpModel); return mpModel; }


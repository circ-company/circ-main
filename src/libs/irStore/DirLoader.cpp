#include "DirLoader.h"

#include <QFileSystemModel>
#include <QTimer>

#include "Log.h"

DirLoader::DirLoader(QObject *parent)
    : QObject{parent}
{
    setObjectName("DirLoader:Null");
}

DirLoader::DirLoader(const FSText &dirName, QObject *parent)
    : QObject{parent}
{
    set(dirName);
    setObjectName("DirLoader:" + basePath()());

}

DirLoader::DirLoader(const QDir &dir, QObject *parent)
    : QObject{parent}
{
    set(dir);
    setObjectName("DirLoader:" + basePath()());
}

void DirLoader::start(const StartOptions opts)
{
    FNENTER();
//    qInfo() << Q_FUNC_INFO << Qt::hex << opts;
  //  LogFunction logFunction(CodeContext(Q_FUNC_INFO, __FILE__, __LINE__));
//    logFunction.add(CodeValue(CodeValue::Argument, int(opts), "opts"));

    mpModel = new QFileSystemModel(this);
    Q_CHECK_PTR(mpModel);
    mpModel->setReadOnly(true);
    mpModel->setOption(QFileSystemModel::DontWatchForChanges, ! (opts & Watch));
    mpModel->setFilter(mBaseDir.filter());
    mpModel->setNameFilters(mBaseDir.nameFilters());
//    connect(this, &DirLoader::dir, this, &DirLoader::processDir);
    connect(this, &DirLoader::file, this, &DirLoader::processFile);

    mpPulseTimer = new QTimer(this);
    Q_CHECK_PTR(mpPulseTimer);
    mpPulseTimer->setInterval(mPulseMsec);
    connect(mpPulseTimer, &QTimer::timeout, this, &DirLoader::pulse);

//    processDir(baseDir(), opts);
}

void DirLoader::start(const FSText &dirName, const StartOptions opts)
{
    FNENTER();
    set(dirName);
    start(opts);
}

void DirLoader::start(const QDir &dir, const StartOptions opts)
{
    FNENTER();
    set(dir);
    start(opts);
}

void DirLoader::processDir(const QDir &dir, const StartOptions opts)
{
    FNENTER();
    mCurrentDir = dir;
    mCurrentOptions = opts;
    mCurrentRow = 0;
    Q_CHECK_PTR(mpModel);
    Q_CHECK_PTR(mpPulseTimer);
    mpPulseTimer->start();
    mParentIndex = mpModel->setRootPath(mCurrentDir.path());
    emit started(mCurrentDir.path());
}

void DirLoader::pulse()
{
    FNENTER();
    int tRows = mpModel->rowCount(mParentIndex);
    if (tRows)
        if (mCurrentRow >= tRows)
        {
            emit dirFinished(mCurrentDir.path());
            return;                                                     /*/===\*/
        }

    mCurrentIndex = mpModel->index(mCurrentRow++, 0, mParentIndex);
    QFileInfo tQFI = mpModel->fileInfo(mCurrentIndex);
    FileInfo tFI(tQFI);
    qInfo() << Q_FUNC_INFO << tRows << mCurrentRow << tFI << tFI.isDir();
    if (tFI.isDir())
        processDir(tFI); // emit dir(tFI);
    else
        emit file(tFI);
}

void DirLoader::processDir(const FileInfo fileInfo)
{
    FNENTER();
    if (mCurrentOptions | SubDirs)
        mSubDirList.append(fileInfo.dir());

}

void DirLoader::processFile(const FileInfo fileInfo)
{
    FNENTER();
    if (mCurrentOptions | Collect)
        mCurrentFiles.append(fileInfo);

}

void DirLoader::set(const FSText &dirName)
{
    mBaseDir.setPath(dirName());
}

void DirLoader::set(const QDir &dir)
{
    mBaseDir.setPath(dir.path());
}

void DirLoader::setFilter(QDir::Filters filters)
{
    mBaseDir.setFilter(filters);
}

void DirLoader::setNameFilters(const QStringList &nameFilters)
{
    mBaseDir.setNameFilters(nameFilters);
}

void DirLoader::setNameFilters(const FSText &suffixNames)
{
    FSText tSufx = suffixNames;
    tSufx += ' ' + suffixNames.toLower();
    FSTextList tNameList(tSufx.simplified().split(' '));
    tNameList.prependEach("*.");
    setNameFilters(tNameList());
}

QStringList DirLoader::toDebugStrings() const
{
    QStringList result;
    result << QString("{==DirLoader:        %1").arg(mBaseDir.path());
    result << QString("---Name Filters:     %1").arg(mBaseDir.nameFilters().join(','));
    result << QString("---Filters:          %1").arg(int(mBaseDir.filter()), 0, 16);
    result << QString("---Exists:           %1").arg(mBaseDir.exists() ? "true" : "false");
    result << QString("---Sub Dirs:         %1").arg(mSubDirList.count());
    return result;
}

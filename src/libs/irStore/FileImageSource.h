#pragma once

#include <QObject>
#include "BaseImageSource.h"

class FileImageSource : public BaseImageSource
{
    Q_OBJECT
public:
    FileImageSource(const QDir aDir, QObject *parent=nullptr);

public slots:
    virtual void checkSource();
    virtual void sourceFinished();

public: // non-const
    virtual void readSource() override;

private:
    QDir mDir;
    QFileInfoList mFIList;
    Count mLoQueuedCount=8;
    Count mHiQueuedCount=16;
};

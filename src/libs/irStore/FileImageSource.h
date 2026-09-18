#pragma once

#include <QObject>
#include "BaseImageSource.h"

class FileImageSource : public BaseImageSource
{
    Q_OBJECT
public:
    FileImageSource(const QDir aDir, QObject *parent=nullptr);

private: // non-const
    virtual void readSource() override;

private:
    FileInfo mFileInfo;
};

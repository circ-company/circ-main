#pragma once

#include <QFileInfo>
#include <QMetaType>

#include <QDir>
#include <QString>

#include <FSText.h>
#include <FSTextList.h>
#include <Null.h>
#include <Types.h>

class QQFileInfo : public QFileInfo, Null
{
public: // ctors
    QQFileInfo(const FSText &filePathName);
    QQFileInfo(const QDir &dir, const QString &fileName);

public: // const
    FSText dirFirst(const qsizetype k) const;
    FSText dirFirst(const qsizetype k, const char ch) const;
    FSText dirLast() const;

private:
    FSTextList mDirNames;

public: // QMetaType
    QQFileInfo() = default;
    ~QQFileInfo() = default;
    QQFileInfo(const QQFileInfo &) = default;
    QQFileInfo &operator=(const QQFileInfo &) = default;
};

Q_DECLARE_METATYPE(QQFileInfo);



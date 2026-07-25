#pragma once

#include <QObject>

#include <QByteArray>
#include <QDir>
#include <QDomDocument>
#include <QDomElement>
#include <QList>
#include <QPair>
#include <QString>

#include <FileInfo.h>
#include <FSText.h>
#include <Key.h>
#include <KeyMap.h>
#include <Status.h>
#include <StatusLevel.h>

class XmlDocObject : public QObject
{
    Q_OBJECT
public: // types
    typedef QPair<Key, QDomElement> KeyElement;

public: // ctor
    explicit XmlDocObject(QObject *parent=nullptr);
    XmlDocObject(const FileInfo &aFileInfo, QObject *parent=nullptr);
    XmlDocObject(const FSText &aFilePathName, QObject *parent=nullptr);
    XmlDocObject(const QDir &aDir, const QString &aFileName, QObject *parent=nullptr);

public slots:
    void clear();
    void set(const FileInfo &aFileInfo);
    void set(const FSText &aFilePathName, QObject *parent=nullptr);
    void set(const QDir &aDir, const QString &aFileName, QObject *parent=nullptr);
    void read(const FileInfo &aFileInfo);
    void read();

signals:
    void cleared();
    void level(const StatusLevel lvl);
    void warning(const StatusLevel lvl);
    void error(const StatusLevel lvl);
    void status(const Status &sts);
    void fileSet(const FileInfo &fileInfo);
    void fileRead(const FileInfo &fileInfo);
    void dataRead(const QByteArray &bytes);
    void docRead(const QDomDocument &doc);
    void rootRead(const QDomElement &rootDE);
    void deRead(const Key &key, const QDomElement &de);
    void mapRead(const KeyTextMap &map);


public: // const
    bool isError() const;
    Status status() const;
    FileInfo fileInfo() const;
    bool exists() const;
    KeyTextMap map() const;

public: // non-const

public: // pointers
    const XmlDocObject * it() const { return this; }
    XmlDocObject * it() { return this; }

private slots:
    void startParse();
    void parseNext();

private:
    Status mStatus;
    FileInfo mFileInfo;
    QByteArray mBytes;
    QDomDocument mDocument;
    QDomElement mRootElement;
    QList<KeyElement> mPendingKeyElements;
    KeyTextMap mKeyMap;
};


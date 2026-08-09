#pragma once

#include <QObject>

#include <QByteArray>
#include <QDir>
#include <QDomDocument>
#include <QDomElement>
#include <QPair>
#include <QQueue>
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
//    typedef QPair<Key, QDomElement> KeyElement;

public: // ctor
    explicit XmlDocObject(QObject *parent=nullptr);
    XmlDocObject(const FileInfo &aFileInfo, QObject *parent=nullptr);
    XmlDocObject(const FSText &aFilePathName, QObject *parent=nullptr);
    XmlDocObject(const QDir &aDir, const QString &aFileName, QObject *parent=nullptr);
    void ctor();

public slots:
    void clear();
    void set(const FileInfo &aFileInfo);
    void set(const FSText &aFilePathName);
    void set(const QDir &aDir, const QString &aFileName);
    bool read(const FileInfo &aFileInfo);
    bool read();
    bool setDocument();
    void finish();

signals:
    void cleared();
    void level(const StatusLevel lvl);
    void warning(const StatusLevel lvl);
    void error(const StatusLevel lvl);
    void status(const Status &sts);
    void fileSet(const FileInfo &fileInfo);
    void fileRead(const FileInfo &fileInfo);
    void dataRead(const QByteArray &bytes);
    void docSetError(const QString &docResult);
    void docSet(const QByteArray &doc);
    void docRead(const QDomDocument &doc);
    void rootRead(const QDomElement &rootDE);
    void deRead(const Key &key, const QDomElement &de);
    void mapRead(const KeyTextMap &map);
    void parsedElement(const QDomElement &de);
    void parseFinished();
    void finished();

public: // const
    bool isError() const;
    Status status() const;
    FileInfo fileInfo() const;
    bool exists() const;
    KeyTextMap map() const;
    KeyTextMap map(const Key &aGroupKey) const;

public: // non-const

public: // pointers
    const XmlDocObject * it() const { return this; }
    XmlDocObject * it() { return this; }

public: // debug
    QStringList toDebugStrings();

private slots:
    void startRoot();
    void parse(const Key &aKey, const QDomElement &aDE);
//    void parseNext();
//    void parseAttributes(const QDomNamedNodeMap &aDNNMap,
  //                       const bool aTrace=false);
    void insert(const Key &aKey, const QString &aValue);

private:
    Status mStatus;
    FileInfo mFileInfo;
    QByteArray mBytes;
    QDomDocument mDocument;
    QDomElement mRootElement;
//    QQueue<KeyElement> mPendingKeyElements;
//    Key mCurrentGroupKey;
    KeyTextMap mKeyMap;
};

inline bool XmlDocObject::isError() const { return status().level().isError(); }
inline Status XmlDocObject::status() const { return mStatus; }
inline FileInfo XmlDocObject::fileInfo() const { return mFileInfo; }
inline KeyTextMap XmlDocObject::map() const { return mKeyMap; }





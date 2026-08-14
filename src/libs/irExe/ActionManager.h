#pragma once

#include <QObject>

#include <QCoreApplication>

#include <KeyMap.h>
#include <Id.h>

class Action;

class ActionManager : public QObject // global static: ACTMGR
{
    Q_OBJECT
public:
    explicit ActionManager(QCoreApplication *parent=qApp);

public slots:
    Action * add(const Key &aKey);

signals:
    void added(const Key &key, const Action * act);

public: // const
    bool contains(const Key &aKey) const;
    Key::List keys() const;
    Action * action(const Key &aKey) const;

public: // non-const
    Uid attachParent(const Uid childUid);

public: // pointer

public: // pointer
    QStringList toDebugStrings() const;

private:
    Id mParentId;
    KeyMapT<Action *> mKeyActionMap;

};

inline bool ActionManager::contains(const Key &aKey) const { return mKeyActionMap.contains(aKey); }
inline Key::List ActionManager::keys() const { return mKeyActionMap.allkeys(); }

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
    Action * add(const Key &key);

signals:
    void added(const Key &key, const Action * act);

public: // const
    Key::List keys() const;

public: // non-const
    Uid attachParent(const Uid childUid);

public: // pointer

private:
    Id mParentId;
    KeyMapT<Action *> mKeyActionMap;

};

inline Key::List ActionManager::keys() const { return mKeyActionMap.allkeys(); }

Q_GLOBAL_STATIC(ActionManager, ACTMGR);

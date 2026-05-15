#pragma once

#include <QList>
#include <QMap>
#include <QNetworkInterface>

#include "AText.h"
#include "Types.h"
#include "XText.h"

class NetworkMacAddress
{
public: // types
    typedef QList<NetworkMacAddress> List;
    typedef QMap<AText, NetworkMacAddress> InterfaceMap;

public: // ctors
    NetworkMacAddress(); // invalid
    NetworkMacAddress(const bool universal); // null or local
    NetworkMacAddress(const QWORD &u48);
    NetworkMacAddress(const DWORD &org24, const DWORD &oui24);
    NetworkMacAddress(const AText &natx);
    NetworkMacAddress(const XText &xtx);

public: // const
    bool isNull() const;
    bool isValid() const;
    bool isOui48() const;
    // TODO isVendor()/isLocal() isUnicast()/isMulticast()
    bool equals(const NetworkMacAddress &other) const;
    BYTE at(const Index ix);
    DWORD org24() const;
    DWORD oui24() const;
    QWORD u48() const;
    AText toText() const;
    bool operator == (const NetworkMacAddress &other);

public: // non-const
    void clear();
    void set(const bool universal); // null or local
    bool set(const QWORD &u48);
    bool set(const DWORD &org24, const DWORD &oui24);
    bool set(const AText &natx);
    bool set(const XText &xtx);

public: // static
    static bool isValid(const QWORD &u48);
    static bool isValid(const AText &natx);
    static bool isValid(const XText &xtx);
    static InterfaceMap interfaceMap();
    static List list();

private:
    QWORD m48bits=0;
    QNetworkInterface mNetIf;
};

inline QWORD NetworkMacAddress::u48() const { return m48bits; }
inline bool NetworkMacAddress::operator ==(const NetworkMacAddress &other) { return equals(other); }
inline void NetworkMacAddress::clear() { m48bits = 0; }

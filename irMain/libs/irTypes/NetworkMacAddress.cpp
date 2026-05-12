#include "NetworkMacAddress.h"

#include <QtDebug>

#include "../../../doctest/doctest/doctest.h"

NetworkMacAddress::NetworkMacAddress() : m48bits(-1) {;} // invalid
NetworkMacAddress::NetworkMacAddress(const bool universal) { set(universal); } // null or local
NetworkMacAddress::NetworkMacAddress(const QWORD &u48) { set(u48); }
NetworkMacAddress::NetworkMacAddress(const DWORD &org24, const DWORD &oui24) { set(org24, oui24); }
NetworkMacAddress::NetworkMacAddress(const AText &natx) { set(natx); }
NetworkMacAddress::NetworkMacAddress(const XText &xtx) { set(xtx); }

TEST_CASE("eirCore/NetworkMacAddress ctors")
{
    NetworkMacAddress nmaInvalid;
    NetworkMacAddress nmaLocal(true);
    NetworkMacAddress nmaNull(false);
    NetworkMacAddress nmaOrgOui(0x00123456, 0x00789ABC);
    NetworkMacAddress nmaNAText("12:34:56-78:9A:BC");
    NetworkMacAddress nmaXText("123456789ABC");

    CHECK( ! nmaInvalid.isValid());
    CHECK( ! nmaInvalid.isNull());
    CHECK(nmaNull.isNull());
    CHECK( ! nmaNull.isValid());
    CHECK( ! nmaLocal.isNull());
    CHECK(nmaLocal.isValid());
    CHECK(nmaOrgOui.isValid());
    CHECK(0x00123456 == nmaOrgOui.org24());
    CHECK(0x00789ABC == nmaOrgOui.oui24());
}


bool NetworkMacAddress::isNull() const
{
    return 0 == m48bits;
}

bool NetworkMacAddress::isValid() const
{
    return isValid(m48bits);
}

bool NetworkMacAddress::isOui48() const
{
    bool result = false;
    if (isValid()) result = m48bits & 0x0000800000000000;
    return result;
}

bool NetworkMacAddress::equals(const NetworkMacAddress &other) const
{
    return m48bits == other.m48bits;
}

BYTE NetworkMacAddress::at(const Index ix)
{
    BYTE result = 0xFF;
    if (ix >= 0 && ix <= 5)
        result = (m48bits >> (ix * 8)) & 0xFF;
    return result;
}

DWORD NetworkMacAddress::org24() const
{
    DWORD result = 0;
    if (isValid()) result = m48bits >> 24;
    return result;
}

DWORD NetworkMacAddress::oui24() const
{
    DWORD result = 0;
    if (isValid()) result = m48bits & 0x0000000000FFFFFF;
    return result;
}

AText NetworkMacAddress::toText() const
{
    QByteArray tBA((const char *)(&m48bits), sizeof(m48bits));
    AText result(tBA.toHex(':'));
    result[9] = '-';
    return result;
}

void NetworkMacAddress::set(const bool universal)
{
    clear();
    if (universal)
    {
        mNetIf = QNetworkInterface::interfaceFromIndex(2);
        QString tHA = mNetIf.hardwareAddress();
        tHA.remove(':');
        const DWORD cOrg = tHA.first(6).toLong(0, 16);
        const DWORD cOui = tHA.last(6).toLong(0, 16);
        set(cOrg, cOui);
//        qDebug() << Q_FUNC_INFO << universal << tHA << mNetIf.hardwareAddress()
  //               << Qt::hex << cOrg << cOui << m48bits;
    }
}

bool NetworkMacAddress::set(const QWORD &u48)
{
    bool result = false;
    if (isValid(u48)) m48bits = u48, result = true;
    return result;
}

bool NetworkMacAddress::set(const DWORD &org24, const DWORD &oui24)
{
    const QWORD cOrgLEQW = qToLittleEndian(org24);
    const QWORD cOuiLEQW = qToLittleEndian(oui24);
    const QWORD c48 = (cOrgLEQW << 24) | cOuiLEQW;
    m48bits = isValid(c48) ? c48 : 0;
//    qDebug() << Q_FUNC_INFO << Qt::hex << org24 << cOrgLEQW << oui24 << cOuiLEQW
  //           << c48 << isValid(c48) << m48bits;
    return isNull();
}

bool NetworkMacAddress::set(const AText &natx)
{
    XText tXt(natx);
    tXt.removeEach(":-");
    return set(tXt);
}

bool NetworkMacAddress::set(const XText &xtx)
{
    QWORD t48 = *QByteArray::fromHex(xtx).constData();
    m48bits = isValid(t48) ? 0 :t48;
//    qDebug() << Q_FUNC_INFO << xtx << Qt::hex << t48 << m48bits << isNull();
    return isNull();
}


bool NetworkMacAddress::isValid(const QWORD &u48)
{
    return u48 >= 0x00000000001000000uLL && u48 <= 0x0000FFFFFFFFFFFFuLL;
}


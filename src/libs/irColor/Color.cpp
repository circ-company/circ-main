#include "Color.h"

#include <Log.h>

Color::Color() { nullify(); }
Color::Color(const Representation aRep, const DWORD aDW) { MUSTDO(); }
Color::Color(const Qt::GlobalColor aGlobal) { set(aGlobal); }

bool Color::isNull(const Representation aRep) const
{
    TriBool tNotNull;
    switch (representation())
    {
    case ORGB:
        tNotNull.expect(notNull(mOpa) || notNull(mAlf));
        tNotNull.expect(notNull(mRed));
        tNotNull.expect(notNull(mGrn));
        tNotNull.expect(notNull(mBlu));
        break;

    case $none:     /* do nothing */                    break;
    default:        MUSTDO("Rep case not handled");     break;
    };

    return ! tNotNull.isTrue();
}

UText Color::name() const
{
    UText result;
    switch (representation())
    {
    case ORGB:
        result = QString("#%1%2%3%4")
                     .arg(opa8(), 16, 2, u'0').arg(red8(), 16, 2, u'0')
                     .arg(grn8(), 16, 2, u'0').arg(blu8(), 16, 2, u'0');
        break;

    case $none:     /* do nothing */                    break;
    default:        MUSTDO("Rep case not handled");     break;
    };
    return result;
}

QColor Color::toQColor() const
{
    return QColor(name());
}

void Color::nullify()
{
    FNENTER();
    mOpa=mAlf=mRed=mGrn=mBlu=mCyn=mMag=mYel=mBlk=
        mCRd=mCBu=mHue=mSat=mVal = 0;
    FNRTNVOID();
}

void Color::greyify()
{
    FNENTER();
    WEXPECTNOT(isNull(representation()));
    switch (representation())
    {
    case GXO:
    case GX:    /* leave it alone */
        break;

    case ORGB:
        {
        const DWORD cRed = DWORD(13932) * DWORD(mRed);
        const DWORD cGrn = DWORD(46871) * DWORD(mGrn);
        const DWORD cBlu = DWORD( 4732) * DWORD(mBlu);
        mVal = DWORD(cRed + cGrn + cBlu) / DWORD(65335);
        mRepresentation = (isNull(mAlf) && isNull(mOpa)) ? GX : GXO;
        if (notNull(mAlf) && isNull(mOpa)) alf2opc();
        }
        break;

    default:
        WARNING("Unhandled Representation");
        break;
    };
    FNRTNVOID();
}

void Color::alf2opc()
{
    if (notNull(mAlf)) mOpa = 65535 - mAlf;
}

void Color::set(const Qt::GlobalColor aGlobal)
{
    QColor tQC(aGlobal);
    set(tQC);
}

void Color::set(const QColor aColor)
{
    setQRgba64(aColor.toRgb().rgba64());
}

void Color::setQRgba64(const QRgba64 aQRgba64)
{
    nullify();
    mRepresentation = ORGB;
    mAlf = aQRgba64.alpha();    alf2opc();
    mRed = aQRgba64.red();
    mBlu = aQRgba64.blue();
    mGrn = aQRgba64.green();
}

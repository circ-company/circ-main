#include "Color.h"

#include <Log.h>

Color::Color(const Representation aRep) : mRepresentation(aRep) {;}
Color::Color(const Representation aRep, const DWORD aDW) { set(aRep, aDW); }
Color::Color(const char *pchNamedColor) { set(pchNamedColor); }
Color::Color(const Qt::GlobalColor aGlobal) { set(aGlobal); }
Color::Color(const QColor aColor, UINT aOpaPerk) { set(aColor, aOpaPerk); }

bool Color::isNull(const Representation aRep) const
{
    TriBool tNotNull;
    switch (aRep)
    {
    case ORGB:
        tNotNull.expect(notNull(mOpa));
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
                     .arg(opa8(), 2, 16, u'0')
                     .arg(red8(), 2, 16, u'0')
                     .arg(grn8(), 2, 16, u'0')
                     .arg(blu8(), 2, 16, u'0');
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

Color Color::lighter(const SWORD aPerk) const
{
    FNENTER();
    FNARG(aPerk, SWORD);
    Color result = it();
    const SDWORD cUnitSDW = 65536L / 1000L;
    if (aPerk == 0) return result;                          /*/===\*/
    const Representation cOrigRep = representation();
    result.convertTo(Biconic);
    DUMPVAR(result.toQColor());
    const SDWORD cValueSDW = SDWORD(mVal);
    const SDWORD cDeltaSDW = cUnitSDW * SDWORD(aPerk);
    SDWORD tResultSDW = cValueSDW + cDeltaSDW;
    result.mVal = WORD(qBound(1L, tResultSDW, 65536L));
    DUMPVAR(result.toQColor());
    result.convertTo(cOrigRep);
    FNRTNVALUE(result.toQColor(), "QColor");
    return result;
}

Color Color::inverted() const
{
    Color result(representation());
    //WORD tTemp;
    DWORD tDW;
    //SWORD tSigned;
    switch (representation())
    {
    case ORGB:
        result.mRed = 65536 - mRed;
        result.mGrn = 65536 - mGrn;
        result.mBlu = 65536 - mBlu;
        break;
    case Biconic:
        tDW = DWORD(mHue) + 32768L;
        if (tDW > 65536L) tDW -= 65536L;
        result.mHue = tDW;
        /* no change in saturation? */
        Q_FALLTHROUGH();
    case GXO:
    case GX:
        result.mVal = 65536 - mVal;
        break;
    case Print:
    case Video:
        WHATDO("Take care of Print and Video");
        break;
    case IX:
        WHATDO("No ColorTable support yet");
        break;
    case AX:
    case OX:
    case $none:
        INFO("No invert for Alpha or Opacity");
        break;
    }
    return result;
}

void Color::nullify()
{
    FNENTER();
    mRepresentation = $none;
    mOpa=mRed=mGrn=mBlu=mCyn=mMag=mYel=mBlk=
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
        mRepresentation = (isNull(mOpa)) ? GX : GXO;
        }
        break;

    default:
        WARNING("Unhandled Representation");
        break;
    };
    FNRTNVOID();
}

void Color::set(const char *pchNamedColor)
{
    MUSTDO();
    Q_UNUSED(pchNamedColor);
}

void Color::set(const Qt::GlobalColor aGlobal)
{
    QColor tQC(aGlobal);
    set(tQC);
}

void Color::set(const QColor aColor, UINT aOpaPerk)
{
    QRgba64 tQRgba64 = aColor.toRgb().rgba64();
    tQRgba64.setAlpha(perkWord(aOpaPerk));
    set(tQRgba64);
}

void Color::set(const QRgba64 aQRgba64)
{
    nullify();
    mRepresentation = ORGB;
    mOpa = aQRgba64.alpha();
    mRed = aQRgba64.red();
    mBlu = aQRgba64.blue();
    mGrn = aQRgba64.green();
}

void Color::set(const Representation aRep, const DWORD aDW)
{
    MUSTDO();
    Q_UNUSED(aRep); Q_UNUSED(aDW);
}

void Color::convertTo(const Representation aRep)
{
    FNENTER();
    FNARG(aRep, "Representation");
    switch (aRep)
    {
    case $none:     nullify();                              break;
    case GXO:       greyify();                              break;
    case Biconic:   toBiconic();                            break;
    default:        WARNING("Unhandled Representation");    break;
    };
    FNRTNVOID();
}

void Color::toBiconic()
{
    QColor tQC = toQColor().convertTo(QColor::Spec::Hsv);
    mVal = WORD(tQC.valueF() * qreal(65536));
    mSat = WORD(tQC.saturationF() * qreal(65536));
    mHue = WORD(tQC.hueF() * qreal(65536));
    mOpa = WORD(tQC.alphaF() * qreal(65536));
}

WORD Color::perkWord(const UINT aPerk)
{
    return WORD((qreal(aPerk) / 1000.0) * 65536.0);
}

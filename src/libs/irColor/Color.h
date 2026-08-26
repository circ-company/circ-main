#pragma once

#include <QColor>
#include <QPixelFormat>
class QRgba;
class QRgba64;

#include <UText.h>
#include <Types.h>

class Color
{
public: // types
    enum Format
    {
        $null       = 0,
        ARGB        = QPixelFormat::RGB,
        BGRA        = QPixelFormat::BGR,
        Index       = QPixelFormat::Indexed,
        Grey        = QPixelFormat::Grayscale,
        Alpha       = QPixelFormat::Alpha,
        CMYK        = QPixelFormat::CMYK,
        AHSL        = QPixelFormat::HSL,
        AHSV        = QPixelFormat::HSV,
        YCC         = QPixelFormat::YUV,
    };
    enum Representation
    {
        $none       = 0,
        ORGB,       // Opacity, Red, Green, Blue
        GXO,        // Grey Value with Opacity
        GX,         // Grey Value only
        IX,
        AX,
        OX,
        Print,      // Cyan Magenta Yellow Black
        Biconic,    // Opacity, Hue, Sat, Value(Lightness)
        Video,      // Opacity, Value(Y), CRd, CBu
    };

public: // ctors
    Color();
    Color(const Representation aRep, const DWORD aDW);
    Color(const char * pchNamedColor);
    Color(const Qt::GlobalColor aGlobal);
    Color(const QColor aColor);
    Color(const QRgba aQRgba);
    Color(const QRgba64 aQRgba64);

public: // const
    Representation representation() const;
    bool isNull(const Representation aRep) const;
    bool isNull(const WORD aWord) const;
    bool notNull(const WORD aWord) const;
    UText name() const;
    QColor toQColor() const;
    QColor operator () () const;
    Color lighter(const SWORD aPerk) const;
    Color darker(const SWORD aPerk) const;
    Color inverted() const;
    BYTE opa8() const { return mOpa >> 8; }
    BYTE red8() const { return mRed >> 8; }
    BYTE grn8() const { return mGrn >> 8; }
    BYTE blu8() const { return mBlu >> 8; }

public: // non-const
    void clear();
    void nullify();
    void greyify();
    void alf2opc();

    void set(const char * pchNamedColor);
    void set(const Qt::GlobalColor aGlobal);
    void set(const QColor aColor);
    void set(const QRgba aQRgba);
    void setQRgba64(const QRgba64 aQRgba64);

private:
    WORD mOpa=0;
    WORD mAlf=0;
    WORD mRed=0;
    WORD mGrn=0;
    WORD mBlu=0;
    WORD mCyn=0;
    WORD mMag=0;
    WORD mYel=0;
    WORD mBlk=0;
    WORD mCRd=0;
    WORD mCBu=0;
    WORD mHue=0;
    WORD mSat=0;
    WORD mVal=0;
    Representation mRepresentation=$none;
};

inline Color::Representation Color::representation() const { return mRepresentation; }
inline bool Color::isNull(const WORD aWord) const { return 0 == aWord; }
inline bool Color::notNull(const WORD aWord) const { return ! isNull(aWord); }
inline QColor Color::operator ()() const { return toQColor(); }
inline void Color::clear() { nullify(); }
inline Color Color::darker(const SWORD aPerk) const { return lighter( - aPerk); }

#include "CText.h"

#include <ctype.h>

char CText::smHingeChar = ' ';

CText::CText() {;}
CText::CText(const char *pch) : AText(pch) {;}
CText::CText(const QByteArray &ba) : AText(ba) {;}
CText::CText(const QByteArray &ba, const QChar repl) : AText(ba, repl) {;}
CText::CText(const QString &s) : AText(s) {;}
CText::CText(const QImage::Format &aQIF) { set(aQIF); }

void CText::set(const QImage::Format &aQIF)
{
    CText tName = QString("Format:Unknown(%1)").arg(aQIF);
    switch (aQIF)
    {
    case QImage::Format_Invalid:                    tName = "Invalid";      break;
    case QImage::Format_Mono:                       tName = "Mono";         break;
    case QImage::Format_MonoLSB:                    tName = "MonoLSB";      break;
    case QImage::Format_Indexed8:                   tName = "Indexed8";     break;
    case QImage::Format_RGB32:                      tName = "RGB32";        break;
    case QImage::Format_ARGB32:                     tName = "ARGB32";       break;
    case QImage::Format_ARGB32_Premultiplied:       tName = "pARGB32";      break;
    case QImage::Format_RGB16:                      tName = "RGB16";        break;
    case QImage::Format_ARGB8565_Premultiplied:     tName = "pARGB8565";    break;
    case QImage::Format_RGB666:                     tName = "RGB666";       break;
    case QImage::Format_ARGB6666_Premultiplied:     tName = "pARGB6666";    break;
    case QImage::Format_RGB555:                     tName = "RGB555";       break;
    case QImage::Format_ARGB8555_Premultiplied:     tName = "pARGB8555";    break;
    case QImage::Format_RGB888:                     tName = "RGB888";       break;
    case QImage::Format_RGB444:                     tName = "RGB444";       break;
    case QImage::Format_ARGB4444_Premultiplied:     tName = "pARGB4444";    break;
    case QImage::Format_RGBX8888:                   tName = "RGBX8888";     break;
    case QImage::Format_RGBA8888:                   tName = "RGBA8888";     break;
    case QImage::Format_RGBA8888_Premultiplied:     tName = "pRGBA8888";    break;
    case QImage::Format_BGR30:                      tName = "BGR30";        break;
    case QImage::Format_A2BGR30_Premultiplied:      tName = "pA2BGR30";     break;
    case QImage::Format_RGB30:                      tName = "RGB30";        break;
    case QImage::Format_A2RGB30_Premultiplied:      tName = "pA2RGB30";     break;
    case QImage::Format_Alpha8:                     tName = "Alpha8";       break;
    case QImage::Format_Grayscale8:                 tName = "Grey8";        break;
    case QImage::Format_RGBX64:                     tName = "RGBX64";       break;
    case QImage::Format_RGBA64:                     tName = "RGBA64";       break;
    case QImage::Format_RGBA64_Premultiplied:       tName = "pRGBA64";      break;
    case QImage::Format_Grayscale16:                tName = "Grey16";       break;
    case QImage::Format_BGR888:                     tName = "BGR888";       break;
    case QImage::Format_RGBX16FPx4:                 tName = "RGBX16FPx4";   break;
    case QImage::Format_RGBA16FPx4:                 tName = "RGBA16FPx4";   break;
    case QImage::Format_RGBA16FPx4_Premultiplied:   tName = "pRGBA16FPx4";  break;
    case QImage::Format_RGBX32FPx4:                 tName = "RGBX32FPx4";   break;
    case QImage::Format_RGBA32FPx4:                 tName = "RGBA32FPx4";   break;
    case QImage::Format_RGBA32FPx4_Premultiplied:   tName = "pRGBA32FPx4";  break;
    case QImage::Format_CMYK8888:                   tName = "CMYK8888";     break;
    default:                                        Q_FALLTHROUGH();
    case QImage::NImageFormats:                                             break;
    };
    it() = tName;
}

bool CText::isValidFirst(const char ch) const
{
    return isupper(ch) || islower(ch);
}

bool CText::isValidChar(const char ch) const
{
    return isupper(ch) || islower(ch) || isdigit(ch);
}

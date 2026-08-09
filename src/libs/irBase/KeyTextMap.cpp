#include "KeyTextMap.h"

KeyTextMap::KeyTextMap() {}

QStringList KeyTextMap::toDebugStrings() const
{
    QStringList result;
    KeyList tKeys = KeyMapT<AText>allKeys();
    result << QString("{KeyTextMap: %1 %2 entries")
                  .arg(name()()).arg(tKeys.count());
    while ( ! tKeys.isEmpty())
    {
        const Key cKey = tKeys.takeFirst();
        const AText cValue = KeyMapT<AText>::value(cKey);
        result << QString("%1 = <%2>(%3)")
            .arg(cKey, -40, u' ').arg(cValue).arg(cValue.length());
    }
    return result;
}

#include "LabelMap.h"

#include <Log.h>

#include "Label.h"

LabelMap::LabelMap(QWidget *labelsParent) : mpLabelsParent(labelsParent) {;}

Label *LabelMap::label(const Key &key) const
{
    return mKeyLabelMap.value(key);
}

Label *LabelMap::add(const Key &key, Label *pLabel)
{
    Label * result = pLabel;
    CKPOINTER(result);
    result->setObjectName("Label:" + key());
    mKeyLabelMap.insert(key, result);
    return result;
}

Label *LabelMap::add(const Key &key, const QString &text)
{
    Label * pLabel = new Label(text, mpLabelsParent);
    return add(key, pLabel);
}

Label *LabelMap::add(const Key &key, const BYTE digits)
{
    Label * pLabel = new Label(digits, mpLabelsParent);
    return add(key, pLabel);
}

Label *LabelMap::add(const Key &key, const QPixmap &pxm)
{
    Label * pLabel = new Label(pxm, mpLabelsParent);
    return add(key, pLabel);
}

Label *LabelMap::add(const Key &key, const QImage &img)
{
    Label * pLabel = new Label(img, mpLabelsParent);
    return add(key, pLabel);
}

void LabelMap::releaseAll()
{
    foreach (Label * pLabel, mKeyLabelMap.values())
        if (pLabel)
            pLabel->deleteLater();
    mKeyLabelMap.clear();
}



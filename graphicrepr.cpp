#include "graphicrepr.h"

QColor GraphicRepr::Color() const
{
    return _material->ambient();
}

void GraphicRepr::setColor(QColor color)
{
    _material->setAmbient(color);
}

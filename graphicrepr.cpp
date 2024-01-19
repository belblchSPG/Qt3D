#include "graphicrepr.h"

GraphicRepr::GraphicRepr(){}

QColor GraphicRepr::Color()
{
    return _color;
}

void GraphicRepr::setColor(QColor color)
{
    _color = color;
}

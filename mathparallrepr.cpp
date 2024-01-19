#include "mathparallrepr.h"

MathParallRepr::MathParallRepr(float width, float height, float length, QVector3D center) :
    _width(width), _height(height), _length(length)
{
    QVector3D cen = {0,0,0};
    _center = cen;
}

float MathParallRepr::Width()
{
    return _width;
}

float MathParallRepr::Height()
{
    return _height;
}

float MathParallRepr::Length()
{
    return _length;
}

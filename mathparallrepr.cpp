#include "mathparallrepr.h"

MathParallRepr::MathParallRepr(float width, float height, float length, QVector3D center)
{
    //qDebug() << "MathParallRepr constructor";
    //qDebug() << "Width = " << width << "Height = " << height << "Length = " << length << "Center = " << center;
    _width = width;
    _height = height;
    _length = length;
    _center = center;
    //qDebug() << "_Width = " << _width << "_Height = " << _height << "_Length = " << _length << "_Center = " << _center;
}

float MathParallRepr::Width() const
{
    return _width;
}

float MathParallRepr::Height() const
{
    return _height;
}

float MathParallRepr::Length() const
{
    return _length;
}

#include "mathparallrepr.h"

MathParallRepr::MathParallRepr()
{
    //qDebug() << "MathParallRepr constructor";
    //qDebug() << "Width = " << width << "Height = " << height << "Length = " << length << "Center = " << center;

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

#include "mathrepresentation.h"

MathRepresentation::MathRepresentation()
{

}

MathRepresentation::MathRepresentation(float width, float height, float length, QVector3D center, float xRot, float yRot, float zRot)
{
    _width = width;
    _height = height;
    _length = length;
    _center = center;
    _xRot = xRot;
    _yRot = yRot;
    _zRot = zRot;
}

QVector3D MathRepresentation::Center()
{
    return _center;
}

float MathRepresentation::Width()
{
    return _width;
}

float MathRepresentation::Height()
{
    return _height;
}

float MathRepresentation::Length()
{
    return _length;
}

float MathRepresentation::XRot()
{
    return _xRot;
}

float MathRepresentation::YRot()
{
    return _yRot;
}

float MathRepresentation::ZRot()
{
    return _zRot;
}

std::vector<QVector3D> MathRepresentation::Vertices()
{
    std::vector<QVector3D> arr(8);

    float halfWidth = _width / 2.0f;
    float halfHeight = _height / 2.0f;
    float halfLength = _length / 2.0f;

   arr.at(0) = _center - QVector3D(halfWidth, halfHeight, halfLength);
   arr.at(1) = arr.at(0) + QVector3D(_width,0,0);
   arr.at(2) = arr.at(0) + QVector3D(0, _height, 0);
   arr.at(3) = arr.at(0) + QVector3D(0, 0, _length);

   arr.at(4) = _center + QVector3D(halfWidth, halfHeight, halfLength);
   arr.at(5) = arr.at(4) - QVector3D(_width,0,0);
   arr.at(6) = arr.at(4) - QVector3D(0, _height, 0);
   arr.at(7) = arr.at(4) - QVector3D(0, 0, _length);

    for(int i = 0; i < arr.size(); ++i)
    {
       arr.at(i) = RotationVector(arr.at(i),QQuaternion(1,_xRot,_yRot,_zRot));
    }

    return arr;
}

QVector3D MathRepresentation::RotationVector(QVector3D v, QQuaternion q)
{
    QQuaternion rotatedQuat = q * QQuaternion(0, v) * q.conjugated();
    return rotatedQuat.vector();
}




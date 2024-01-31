#ifndef MATHREPRESENTATION_H
#define MATHREPRESENTATION_H

#include <QVector3D>
#include <QQuaternion>
#include <iostream>
#include <ostream>
#include <vector>
#include <math.h>


//Класс отвечает за математическое представление параллелепипеда
class MathRepresentation
{
public:
    MathRepresentation();
    MathRepresentation(float, float, float, QVector3D, float, float, float);
    QVector3D Center();
    float Width();
    float Height();
    float Length();
    float XRot();
    float YRot();
    float ZRot();
    std::vector<QVector3D> Vertices();

    QVector3D RotationVector(QVector3D, QQuaternion);
    std::vector<QVector3D> GetAxis(std::vector<QVector3D>,std::vector<QVector3D>);


private:
    QVector3D _center;
    float _width;
    float _height;
    float _length;
    float _xRot = 0;
    float _yRot = 0;
    float _zRot = 0;
};

#endif // MATHREPRESENTATION_H

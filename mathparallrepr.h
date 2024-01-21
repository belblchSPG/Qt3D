#ifndef MATHPARALLREPR_H
#define MATHPARALLREPR_H

#include "mathrepr.h"

//Данный класс хранит в себе математическое представление параллелепипеда на сцене
//Хранит информацию о длине, высоте, ширине параллелепипеда
class MathParallRepr : public MathRepr
{
public:
    MathParallRepr(float, float, float, QVector3D);

    float Width() const;
    float Height() const;
    float Length() const;

private:
    float _width;
    float _height;
    float _length;
};
#endif // MATHPARALLREPR_H

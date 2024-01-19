#ifndef MATHREPR_H
#define MATHREPR_H

#include <QVector3D>


//Родительский класс, который хранит в себе информацию о центре объекта
//Будет хранит в себе абстрактные методы для дочерних классов
class MathRepr
{
public:
    MathRepr();
    QVector3D Center();

protected:
    QVector3D _center;
};

#endif // MATHREPR_H

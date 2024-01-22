#ifndef PARALLELEPIPED_H
#define PARALLELEPIPED_H

#include "object.h"
#include "graphicparallrepr.h"
#include "mathparallrepr.h"

#include <stdexcept>
#include <memory>

//Класс, который отвечает за представление параллелепипеда на сцене.
//В нем хранится раздельное представление математики и графики объекта
class Parallelepiped : public Object
{
private:
    std::unique_ptr<MathParallRepr> _parallMath;
    std::unique_ptr<GraphicParallRepr> _parallGraphic;

public:
    Parallelepiped(float, float, float, QVector3D, Qt3DCore::QEntity*);

    GraphicParallRepr* GraphicsRepr() const;
    MathParallRepr* MathRepr() const;
};

#endif // PARALLELEPIPED_H

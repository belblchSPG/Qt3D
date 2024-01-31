#ifndef PARALLELEPIPED_H
#define PARALLELEPIPED_H

#include "mathrepresentation.h"
#include "graphicrepresentation.h"

#include <stdexcept>
#include <memory>

//Класс, который отвечает за представление параллелепипеда на сцене.
//В нем хранится раздельное представление математики и графики объекта
class Parallelepiped
{
private:
    std::unique_ptr<MathRepresentation> _parallMath;
    std::unique_ptr<GraphicRepresentation> _parallGraphic;

public:

    GraphicRepresentation *GraphicsRepr() const;
    MathRepresentation *MathRepr() const;
    Parallelepiped(float width, float height, float length, QVector3D center, float xRot, float yRot, float zRot, Qt3DCore::QEntity *rootEntity);
};

#endif // PARALLELEPIPED_H

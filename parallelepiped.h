#ifndef PARALLELEPIPED_H
#define PARALLELEPIPED_H

#include "graphicparallrepr.h"
#include "mathparallrepr.h"

#include <Qt3DExtras>
#include <Qt3DCore>

#include <QVector3D>
#include <QColor>
#include <stdexcept>

//Класс, который отвечает за представление параллелепипеда на сцене.
//В нем хранится разделное представление математики и графики объекта
class Parallelepiped
{
public:
    Parallelepiped(float, float, float, QVector3D, Qt3DCore::QEntity*);

private:
    MathParallRepr* _parallMath;
    GraphicParallRepr* _parallGraphic;
};

#endif // PARALLELEPIPED_H

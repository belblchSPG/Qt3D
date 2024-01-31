#ifndef COLLISIONDETECTOR_H
#define COLLISIONDETECTOR_H

#include "parallelepiped.h"

#include <vector>

enum IntersectionType : int{
    NoIntersection = 0,
    SharedVertex = 1, // rgb(170, 130, 140)
    PartialIntersection = 2, //cyan
    FullIntersection = 3 //blue
};

//Класс, который будет выполнять проверку столкновений по данным об объектах, которые будут приходить в него
class CollisionDetector
{
public:
    CollisionDetector();
    std::vector<std::tuple<Parallelepiped*,Parallelepiped*,IntersectionType>> CollisionDetection(const std::vector<Parallelepiped*>&);

private:

    float ProjVector3(QVector3D v, QVector3D a);
    void ProjAxis(float& min, float& max, const std::vector<QVector3D>& points, const QVector3D& axis);
    IntersectionType IntersectionOfProj(const std::vector<QVector3D> a, const std::vector<QVector3D> b, const std::vector<QVector3D>& axis);
    IntersectionType Collision(Parallelepiped* box1, Parallelepiped* box2);
};

#endif // COLLISIONDETECTOR_H

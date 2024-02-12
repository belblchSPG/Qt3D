#ifndef COLLISIONDETECTOR_H
#define COLLISIONDETECTOR_H

#include "GA.h"
#include "gacube.h"


namespace GA
{

//Класс, который будет выполнять проверку столкновений по данным об объектах, которые будут приходить в него
class CollisionDetector
{
public:
    CollisionDetector();
    std::vector<std::tuple<GACube*,GACube*,IntersectionType>> CollisionDetection(const std::vector<GACube*>&);

private:

    float ProjVector3(QVector3D v, QVector3D a);
    void ProjAxis(float& min, float& max, const std::vector<QVector3D>& points, const QVector3D& axis);
    IntersectionType IntersectionOfProj(const std::vector<QVector3D> a, const std::vector<QVector3D> b, const std::vector<QVector3D>& axis);
    //IntersectionType Collision(GA::GACube* box1, GA::GACube* box2);
};
}
#endif // COLLISIONDETECTOR_H

#ifndef GACOLLISIONDETECTOR_H
#define GACOLLISIONDETECTOR_H

#include "GA.h"
#include "gacube.h"

using namespace GA;

namespace GA
{

//Класс, который будет выполнять проверку столкновений по данным об объектах, которые будут приходить в него
class GACollisionDetector
{
public:
    GACollisionDetector();
    std::vector<std::tuple<GACube*,GACube*,GA::IntersectionType>> CollisionDetection(const std::vector<GACube*>&);

private:

    double ProjVector3(GA::Vector3D v, GA::Vector3D a);
    void ProjAxis(double& min, double& max, const std::vector<GA::Vector3D>& points, const GA::Vector3D& axis);
    IntersectionType IntersectionOfProj(const std::vector<GA::Vector3D> a, const std::vector<GA::Vector3D> b, const std::vector<GA::Vector3D>& axis);
    //IntersectionType Collision(GA::GACube* box1, GA::GACube* box2);
};
}
#endif // GACOLLISIONDETECTOR_H

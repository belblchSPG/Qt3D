#ifndef COLLISIONDETECTOR_H
#define COLLISIONDETECTOR_H

#include "parallelepiped.h"

#include <vector>

//Класс, который будет выполнять проверку столкновений по данным об объектах, которые будут приходить в него
class CollisionDetector
{
public:
    CollisionDetector();
    void CollisionDetection(const std::vector<Parallelepiped*>&);

private:
    bool CheckCollision(Parallelepiped*,Parallelepiped*) const;
};

#endif // COLLISIONDETECTOR_H

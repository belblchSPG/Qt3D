#include "collisiondetector.h"

CollisionDetector::CollisionDetector() {}

void CollisionDetector::CollisionDetection(const std::vector<Parallelepiped*>& objects)
{
   qDebug() << "Collision detection started";

   for (size_t i = 0; i < objects.size(); ++i)
   {
       for (size_t j = i + 1; j < objects.size(); ++j)
       {
           Parallelepiped* c1 = objects[i];
           Parallelepiped* c2 = objects[j];
           qDebug() << "Check " << c1 << "and " << c2;
           if (CheckCollision(c1, c2))
           {

               c1->GraphicsRepr()->setColor(Qt::red);
               c2->GraphicsRepr()->setColor(Qt::red);
           }
           else
           {
               if(c1->GraphicsRepr()->Color()!=Qt::red)
               {
                   c1->GraphicsRepr()->setColor(Qt::green);
               }
               if(c2->GraphicsRepr()->Color()!=Qt::red)
               {
                   c2->GraphicsRepr()->setColor(Qt::green);
               }
           }
       }
       }
   }

bool CollisionDetector::CheckCollision(Parallelepiped *p1, Parallelepiped *p2) const
{
    // Проекции по осям
    bool overlapX = (p1->MathRepr()->Center().x() - p1->MathRepr()->Width()/2) <= (p2->MathRepr()->Center().x() + p2->MathRepr()->Width()/2) &&
                    (p1->MathRepr()->Center().x() + p1->MathRepr()->Width()/2) >= (p2->MathRepr()->Center().x() - p2->MathRepr()->Width()/2);

    bool overlapY = (p1->MathRepr()->Center().y() - p1->MathRepr()->Height()/2) <= (p2->MathRepr()->Center().y() + p2->MathRepr()->Height()/2) &&
                    (p1->MathRepr()->Center().y() + p1->MathRepr()->Height()/2) >= (p2->MathRepr()->Center().y() - p2->MathRepr()->Height()/2);

    bool overlapZ = (p1->MathRepr()->Center().z() - p1->MathRepr()->Length()/2) <= (p2->MathRepr()->Center().z() + p2->MathRepr()->Length()/2) &&
                    (p1->MathRepr()->Center().z() + p1->MathRepr()->Length()/2) >= (p2->MathRepr()->Center().z() - p2->MathRepr()->Length()/2);

    return overlapX && overlapY && overlapZ;
}

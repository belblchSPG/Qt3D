#include "collisiondetector.h"

CollisionDetector::CollisionDetector() {}

void CollisionDetector::CollisionDetection(std::vector<Parallelepiped*> objects)
{
    qDebug() << "Collision detection started";

    // Перебираем все кубоиды на сцене
    for (Parallelepiped* c1 : objects)
    {
        // Перебираем остальные кубоиды для проверки пересечения
        for (Parallelepiped* c2 : objects)
        {
            // Исключаем сравнение кубоидов с собой
            if (c1 != c2)
            {
                qDebug() << "Check " << c1 << "and " << c2;
                // Проверка на пересечение
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

#include "collisiondetector.h"

GA::CollisionDetector::CollisionDetector() {}

std::vector<std::tuple<GA::GACube*,GA::GACube*,GA::IntersectionType>> GA::CollisionDetector::CollisionDetection(const std::vector<GA::GACube*>& objects)
{
   //qDebug() << "Collision detection started";

   std::vector<std::tuple<GA::GACube*,GA::GACube*,IntersectionType>> collisions;

   if(objects.size() == 1)
   {
       collisions.push_back(std::tuple<GA::GACube*,GA::GACube*,IntersectionType>(objects[0],nullptr,GA::IntersectionType::NoIntersection));
   }

   for (size_t i = 0; i < objects.size(); ++i)
   {
       for (size_t j = i + 1; j < objects.size(); ++j)
       {
           GA::GACube* c1 = objects[i];
           GA::GACube* c2 = objects[j];
           //qDebug() << "Check " << c1 << "and " << c2;

          // collisions.push_back(std::tuple<GA::GACube*,GA::GACube*,GA::IntersectionType>(c1,c2,Collision(c1,c2)));
       }
    }
   return collisions;
}
bool SharedVertexesDetection(GA::GACube *p1, GA::GACube *p2)
{
    QVector3D center1 = p1->getMathRepresentation().Center();
    QVector3D center2 = p2->getMathRepresentation().Center();

    float halfWidth1 = p1->getMathRepresentation().Width() / 2.0f;
    float halfHeight1 = p1->getMathRepresentation().Height() / 2.0f;
    float halfLength1 = p1->getMathRepresentation().Length() / 2.0f;

    float halfWidth2 = p2->getMathRepresentation().Width() / 2.0f;
    float halfHeight2 = p2->getMathRepresentation().Height() / 2.0f;
    float halfLength2 = p2->getMathRepresentation().Length() / 2.0f;

    // Вершины параллелепипедов
    QVector3D vertices1[8] = {
        center1 + QVector3D(halfWidth1, halfHeight1, halfLength1),
        center1 + QVector3D(halfWidth1, halfHeight1, -halfLength1),
        center1 + QVector3D(halfWidth1, -halfHeight1, halfLength1),
        center1 + QVector3D(halfWidth1, -halfHeight1, -halfLength1),
        center1 + QVector3D(-halfWidth1, halfHeight1, halfLength1),
        center1 + QVector3D(-halfWidth1, halfHeight1, -halfLength1),
        center1 + QVector3D(-halfWidth1, -halfHeight1, halfLength1),
        center1 + QVector3D(-halfWidth1, -halfHeight1, -halfLength1)
    };

    QVector3D vertices2[8] = {
        center2 + QVector3D(halfWidth2, halfHeight2, halfLength2),
        center2 + QVector3D(halfWidth2, halfHeight2, -halfLength2),
        center2 + QVector3D(halfWidth2, -halfHeight2, halfLength2),
        center2 + QVector3D(halfWidth2, -halfHeight2, -halfLength2),
        center2 + QVector3D(-halfWidth2, halfHeight2, halfLength2),
        center2 + QVector3D(-halfWidth2, halfHeight2, -halfLength2),
        center2 + QVector3D(-halfWidth2, -halfHeight2, halfLength2),
        center2 + QVector3D(-halfWidth2, -halfHeight2, -halfLength2)
    };

    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < 8; ++j)
        {
            if(vertices1[i] == vertices2[j])
            {
                return true;
            }
        }
    }
    return false;
}

std::vector<QVector3D> GetAxis(std::vector<QVector3D> a, std::vector<QVector3D> b)
{
    QVector3D A;
    QVector3D B;

    std::vector<QVector3D> axis;

    for(int i = 1; i < 4; ++i)
    {
        A = a[i] - a[0];
        B = a[(i+1)%3+1] - a[0];
        axis.push_back(QVector3D::crossProduct(A,B).normalized());
    }

    for (int i = 1; i < 4; i++)
    {
        A = b[i] - b[0];
        B = b[(i+1)%3+1] - b[0];
        axis.push_back(QVector3D::crossProduct(A,B).normalized());
    }

    for (int i = 1; i < 4; i++)
    {
        A = a[i] - a[0];
        for (int j = 1; j < 4; j++)
        {
            B = b[j] - b[0];
            if (QVector3D::crossProduct(A,B).length() != 0)
            {
                axis.push_back(QVector3D::crossProduct(A,B).normalized());
            }
        }
    }
    return axis;
}

float GA::CollisionDetector::ProjVector3(QVector3D v, QVector3D a)
{
    a = a.normalized();
    return QVector3D::dotProduct(v, a) / a.length();
}

void GA::CollisionDetector::ProjAxis(float& min, float& max, const std::vector<QVector3D>& points, const QVector3D& axis)
{
    max = QVector3D::dotProduct(points[0], axis);
    min = max;

    max = ProjVector3(points[0], axis);
    min = ProjVector3(points[0], axis);

    for (int i = 1; i < 4; i++)
    {
        float tmp = ProjVector3(points[i], axis);

        if (tmp > max)
        {
            max = tmp;
        }

        if (tmp < min)
        {
            min = tmp;
        }
    }
}

GA::IntersectionType GA::CollisionDetector::IntersectionOfProj(const std::vector<QVector3D> a, const std::vector<QVector3D> b, const std::vector<QVector3D>& axis)
{
    QVector3D norm(10000,10000,10000);
    for (int j = 0; j < axis.size(); j++)
    {
        //проекции куба a
        float max_a;
        float min_a;
        ProjAxis(min_a,max_a,a,axis[j]);

        //проекции куба b
        float max_b;
        float min_b;
        ProjAxis(min_b,max_b,b,axis[j]);

        std::vector<float> points = {min_a, max_a, min_b, max_b};
        std::sort(points.begin(), points.end());

        float sum = (max_b - min_b) + (max_a - min_a);
        float len = std::abs(points[3] - points[0]);

        qDebug() << sum << len;

        if(len*2==sum)
        {
            return IntersectionType::FullIntersection;
        }

        if(sum == len)
        {
            return IntersectionType::SharedVertex;
        }

        if (sum > len)
        {
            return IntersectionType::PartialIntersection;
        }
    }

    return IntersectionType::NoIntersection;
}

//GA::IntersectionType GA::CollisionDetector::Collision(GA::GACube* box1, GA::GACube* box2)
//{
   //std::vector<QVector3D> points1 = box1->MathRepr()->Vertices();

   //std::vector<QVector3D> points2 = box2->MathRepr()->Vertices();

   //std::vector<QVector3D> axis = GetAxis(points1, points2);

   //return IntersectionOfProj(points1, points2, axis);

//}

//Oriented Bounding Box collision detection
//separate axis theorem collisin detection

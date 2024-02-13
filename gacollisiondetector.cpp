#include "gacollisiondetector.h"

GA::GACollisionDetector::GACollisionDetector() {}

std::vector<std::tuple<GACube*,GACube*,GA::IntersectionType>> GACollisionDetector::CollisionDetection(const std::vector<GACube*>& objects)
{
   //qDebug() << "Collision detection started";

   std::vector<std::tuple<GACube*,GACube*,GA::IntersectionType>> collisions;

   if(objects.size() == 1)
   {
       collisions.push_back(std::tuple<GACube*,GACube*,GA::IntersectionType>(objects[0],nullptr,GA::IntersectionType::NoIntersection));
   }

   for (size_t i = 0; i < objects.size(); ++i)
   {
       for (size_t j = i + 1; j < objects.size(); ++j)
       {
           GACube* c1 = objects[i];
           GACube* c2 = objects[j];
           //qDebug() << "Check " << c1 << "and " << c2;

          // collisions.push_back(std::tuple<GA::GACube*,GA::GACube*,GA::IntersectionType>(c1,c2,Collision(c1,c2)));
       }
    }
   return collisions;
}

bool SharedVertexesDetection(GACube *p1, GACube *p2)
{
    GA::Vector3D center1 = p1->getMathRepresentation().Center();
    GA::Vector3D center2 = p2->getMathRepresentation().Center();

    float halfWidth1 = p1->getMathRepresentation().Width() / 2.0f;
    float halfHeight1 = p1->getMathRepresentation().Height() / 2.0f;
    float halfLength1 = p1->getMathRepresentation().Length() / 2.0f;

    float halfWidth2 = p2->getMathRepresentation().Width() / 2.0f;
    float halfHeight2 = p2->getMathRepresentation().Height() / 2.0f;
    float halfLength2 = p2->getMathRepresentation().Length() / 2.0f;

    // Вершины параллелепипедов
    GA::Vector3D vertices1[8] = {
        center1 + GA::Vector3D(halfWidth1, halfHeight1, halfLength1),
        center1 + GA::Vector3D(halfWidth1, halfHeight1, -halfLength1),
        center1 + GA::Vector3D(halfWidth1, -halfHeight1, halfLength1),
        center1 + GA::Vector3D(halfWidth1, -halfHeight1, -halfLength1),
        center1 + GA::Vector3D(-halfWidth1, halfHeight1, halfLength1),
        center1 + GA::Vector3D(-halfWidth1, halfHeight1, -halfLength1),
        center1 + GA::Vector3D(-halfWidth1, -halfHeight1, halfLength1),
        center1 + GA::Vector3D(-halfWidth1, -halfHeight1, -halfLength1)
    };

    GA::Vector3D vertices2[8] = {
        center2 + GA::Vector3D(halfWidth2, halfHeight2, halfLength2),
        center2 + GA::Vector3D(halfWidth2, halfHeight2, -halfLength2),
        center2 + GA::Vector3D(halfWidth2, -halfHeight2, halfLength2),
        center2 + GA::Vector3D(halfWidth2, -halfHeight2, -halfLength2),
        center2 + GA::Vector3D(-halfWidth2, halfHeight2, halfLength2),
        center2 + GA::Vector3D(-halfWidth2, halfHeight2, -halfLength2),
        center2 + GA::Vector3D(-halfWidth2, -halfHeight2, halfLength2),
        center2 + GA::Vector3D(-halfWidth2, -halfHeight2, -halfLength2)
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

std::vector<GA::Vector3D> GetAxis(std::vector<GA::Vector3D> a, std::vector<GA::Vector3D> b)
{
    GA::Vector3D A;
    GA::Vector3D B;

    std::vector<GA::Vector3D> axis;

    for(int i = 1; i < 4; ++i)
    {
        A = a[i] - a[0];
        B = a[(i+1)%3+1] - a[0];
        axis.push_back(GA::Vector3D::crossProduct(A,B).normalized());
    }

    for (int i = 1; i < 4; i++)
    {
        A = b[i] - b[0];
        B = b[(i+1)%3+1] - b[0];
        axis.push_back(GA::Vector3D::crossProduct(A,B).normalized());
    }

    for (int i = 1; i < 4; i++)
    {
        A = a[i] - a[0];
        for (int j = 1; j < 4; j++)
        {
            B = b[j] - b[0];
            if (GA::Vector3D::crossProduct(A,B).length() != 0)
            {
                axis.push_back(GA::Vector3D::crossProduct(A,B).normalized());
            }
        }
    }
    return axis;
}

double GACollisionDetector::ProjVector3(GA::Vector3D v, GA::Vector3D a)
{
    a = a.normalized();
    return GA::Vector3D::dotProduct(v, a) / a.length();
}

void GACollisionDetector::ProjAxis(double& min, double& max, const std::vector<GA::Vector3D>& points, const GA::Vector3D& axis)
{
    max = GA::Vector3D::dotProduct(points[0], axis);
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

GA::IntersectionType GACollisionDetector::IntersectionOfProj(const std::vector<GA::Vector3D> a, const std::vector<GA::Vector3D> b, const std::vector<GA::Vector3D>& axis)
{
    GA::Vector3D norm(10000,10000,10000);
    for (int j = 0; j < axis.size(); j++)
    {
        //проекции куба a
        double max_a;
        double min_a;
        ProjAxis(min_a,max_a,a,axis[j]);

        //проекции куба b
        double max_b;
        double min_b;
        ProjAxis(min_b,max_b,b,axis[j]);

        std::vector<double> points = {min_a, max_a, min_b, max_b};
        std::sort(points.begin(), points.end());

        double sum = (max_b - min_b) + (max_a - min_a);
        double len = std::abs(points[3] - points[0]);

        qDebug() << sum << len;

        if(len*2==sum)
        {
            return GA::IntersectionType::FullIntersection;
        }

        if(sum == len)
        {
            return GA::IntersectionType::SharedVertex;
        }

        if (sum > len)
        {
            return GA::IntersectionType::PartialIntersection;
        }
    }

    return GA::IntersectionType::NoIntersection;
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

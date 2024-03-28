#include "../headers/cd_detector.h"
#include <vector>
#include <iostream>
#include <QDebug>

double Det2D(const CDPoint &p1, const CDPoint &p2, const CDPoint &p3)
{
    return +p1.first*(p2.second-p3.second)
           +p2.first*(p3.second-p1.second)
           +p3.first*(p1.second-p2.second);
}

void CheckTriWinding(CDPoint &p1, CDPoint &p2, CDPoint &p3)
{
    double detTri = Det2D(p1, p2, p3);
    if(detTri < 0.0)
    {
        CDPoint a = p3;
        p3 = p2;
        p2 = a;
    }
}

bool BoundaryCollideChk(CDPoint &p1, CDPoint &p2, CDPoint &p3)
{
    return Det2D(p1, p2, p3) < 0.0;
}

CDIntersectionResult CDDetector::ConturCollision( CDContur* c1, CDContur* c2) const
{
    auto t1 = c1->GetPoints();
    auto t2 = c2->GetPoints();

    qDebug() << "Started detection";

    //Trangles must be expressed anti-clockwise
    CheckTriWinding(t1[0], t1[1], t1[2]);
    CheckTriWinding(t2[0], t2[1], t2[2]);


    //For edge E of trangle 1,
    for(int i=0; i<3; i++)
    {
        int j=(i+1)%3;

        //Check all points of trangle 2 lay on the external side of the edge E. If
        //they do, the triangles do not collide.
        if (BoundaryCollideChk(t1[i], t1[j], t2[0]) &&
            BoundaryCollideChk(t1[i], t1[j], t2[1]) &&
            BoundaryCollideChk(t1[i], t1[j], t2[2]))
            return NoIntersection;;
    }

    //For edge E of trangle 2,
    for(int i=0; i<3; i++)
    {
        int j=(i+1)%3;

        //Check all points of trangle 1 lay on the external side of the edge E. If
        //they do, the triangles do not collide.
        if (BoundaryCollideChk(t2[i], t2[j], t1[0]) &&
            BoundaryCollideChk(t2[i], t2[j], t1[1]) &&
            BoundaryCollideChk(t2[i], t2[j], t1[2]))
            return NoIntersection;;
    }

    //The triangles collide
    return Intersection;;
}

CDDetector::~CDDetector()
{
    //for(int i = 0; i < m_geometry.size(); ++i)
    //{
    //    delete m_geometry[i];
    //}

    m_geometry.clear();
}

void CDDetector::AddGeom(CDContur* contur)
{
    m_geometry.push_back(contur);
}

void CDDetector::AddGeom(std::vector<CDPoint> points)
{
    m_geometry.push_back(new CDContur(points));
}

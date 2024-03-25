#include "cd_detector.h"
#include <vector>
#include <iostream>

double Det2D(CDPoint &p1, CDPoint &p2, CDPoint &p3)
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

CD::IntersectionType CDDetector::ConturCollision2D(CDContur c1, CDContur c2)
{
    auto t1 = c1.getPoints();
    auto t2 = c2.getPoints();

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
            return CD::NoIntersection;;
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
            return CD::NoIntersection;;
    }

    //The triangles collide
    return CD::Intersection;;
}


CDDetector::CDDetector()
{

}

//CD::IntersectionType CDDetector::checkCollision(const CDContur& c1, const CDContur& c2)
//{
//    auto P1 = c1.getPoints();
//    auto P2 = c2.getPoints();
//
//    for (int i = 0; i < 3; ++i) {
//        std::vector<std::vector<double>> edge(2, std::vector<double>(2));
//        edge[0] = {std::get<0>(P1[i]), std::get<1>(P1[i])};
//        edge[1] = {std::get<0>(P1[(i + 1) % 3]), std::get<1>(P1[(i + 1) % 3])};
//
//        if (BoundaryCollideChk({edge[0], edge[1], std::get<0>(P2[0]), std::get<1>(P2[0])}) &&
//            BoundaryCollideChk({edge[0], edge[1], std::get<0>(P2[1]), std::get<1>(P2[1])}) &&
//            chkEdge({edge[0], edge[1], std::get<0>(P2[2]), std::get<1>(P2[2])})) {
//            return CD::NoIntersection;
//        }
//    }
//
//    for (int i = 0; i < 3; ++i) {
//        std::vector<std::vector<double>> edge(2, std::vector<double>(2));
//        edge[0] = {P2[i].x, P2[i].y};
//        edge[1] = {P2[(i + 1) % 3].x, P2[(i + 1) % 3].y};
//
//        if (chkEdge({edge[0], edge[1], {P1[0].x, P1[0].y}}) &&
//            chkEdge({edge[0], edge[1], {P1[1].x, P1[1].y}}) &&
//            chkEdge({edge[0], edge[1], {P1[2].x, P1[2].y}})) {
//            return CD::NoIntersection;
//        }
//    }
//
//    return CD::Intersection;
//}


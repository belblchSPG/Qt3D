#ifndef __CD_H
#define __CD_H

#include <vector>
#include <utility>

namespace CD{

enum IntersectionType : int{
    NoIntersection = 0,
    Intersection = 1
};

}
using CDPoint = std::pair<double, double>;

class CDLine;
class CDContur;
class CDTriangle;
class CDRectangle;
class CDCircle;
class CDDetector;


#endif // CD_H

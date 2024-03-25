#ifndef __CDDETECTOR_H
#define __CDDETECTOR_H

#include "cd.h"
#include "cd_contur.h"

class CDDetector
{

private:

public:

    CDDetector();

    CD::IntersectionType checkCollision(const CDContur& c1, const CDContur& c2);

    CD::IntersectionType ConturCollision2D(CDContur c1, CDContur c2);
};

#define CHECK_INTERSECTION(detector, c1, c2) detector.ConturCollision2D(c1, c2)

#endif // CDDETECTOR_H

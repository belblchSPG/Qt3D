#ifndef __CDCONTUR_H
#define __CDCONTUR_H

#include "cd.h"

class CDContur
{

private:

    std::vector<CDPoint> m_points;

public:

    CDContur(CDPoint p1 ,CDPoint p2,CDPoint p3);

    std::vector<CDPoint> getPoints() const;
};

#endif // CDCONTUR_H

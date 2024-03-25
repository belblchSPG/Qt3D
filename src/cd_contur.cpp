#include "cd_contur.h"

CDContur::CDContur(CDPoint p1, CDPoint p2, CDPoint p3)
{
    m_points.clear();
    m_points.push_back(p1);
    m_points.push_back(p2);
    m_points.push_back(p3);
}

std::vector<CDPoint> CDContur::getPoints() const
{
    return m_points;
}

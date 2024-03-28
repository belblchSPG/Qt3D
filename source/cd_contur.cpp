#include "../headers/cd_contur.h"

CDContur::CDContur(CDPoint p1, CDPoint p2, CDPoint p3)
{
    m_points.clear();
    m_points.push_back(p1);
    m_points.push_back(p2);
    m_points.push_back(p3);
}

CDContur::~CDContur()
{
    m_points.clear();
}

CDContur::CDContur(std::vector<CDPoint> points)
{
    if(points.size() == 3)
    {
        m_points.clear();
        m_points.push_back(points[0]);
        m_points.push_back(points[0]);
        m_points.push_back(points[0]);
    }
}

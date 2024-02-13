#include "gacubemathrepresentation.h"

GACubeMathRepresentation::GACubeMathRepresentation(GA::Vector3D mathInfo[3])
{
    if(mathInfo[0].x() <= 0 || mathInfo[0].y() <= 0 || mathInfo[0].z() <= 0)
    {
        m_dimensions = {-1,-1,-1};
        m_center = {-1,-1,-1};
        m_rotation = {-1,-1,-1};
        return;
    }
    m_dimensions = mathInfo[0];
    m_center = mathInfo[1];
    m_rotation = mathInfo[2];
}

GA::Point GACubeMathRepresentation::Center() const
{
    return m_center;
}

double GACubeMathRepresentation::Width() const
{
    return m_dimensions.x();
}

double GACubeMathRepresentation::Height() const
{
    return m_dimensions.y();
}

double GACubeMathRepresentation::Length() const
{
    return m_dimensions.z();
}

double GACubeMathRepresentation::XRot() const
{
    return m_rotation.x();
}

double GACubeMathRepresentation::YRot() const
{
    return m_rotation.y();
}

double GACubeMathRepresentation::ZRot() const
{
    return m_rotation.z();
}

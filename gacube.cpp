#include "gacube.h"

GA::GACube::GACube(const GACubeMathRepresentation &math) :
    m_mathRepresentation(math), m_graphicRepresentation(new GA::GACubeGraphicRepresentation(math)){}

GA::GACube::~GACube()
{
    delete m_graphicRepresentation;
}

GA::GACubeMathRepresentation GA::GACube::getMathRepresentation() const
{
    return m_mathRepresentation;
}

GA::GACubeGraphicRepresentation& GA::GACube::getGraphicsRepresentation() const
{
    return *m_graphicRepresentation;
}

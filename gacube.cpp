#include "gacube.h"

GACube::GACube(const GACubeMathRepresentation &math) :
    m_mathRepresentation(math), m_graphicRepresentation(new GACubeGraphicRepresentation(math)){}

GACube::~GACube()
{
    delete m_graphicRepresentation;
}

GACubeMathRepresentation GACube::getMathRepresentation() const
{
    return m_mathRepresentation;
}

GACubeGraphicRepresentation& GACube::getGraphicsRepresentation() const
{
    return *m_graphicRepresentation;
}

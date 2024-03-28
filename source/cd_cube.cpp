#include "../headers/cd_cube.h"

GACube::GACube(const GACubeMathRepresentation &math) :
    m_mathRepresentation(math), m_graphicRepresentation(new GACubeGraphicRepresentation(math)){}

GACube::~GACube()
{
    delete m_graphicRepresentation;
}

GACubeMathRepresentation GACube::GetMathRepresentation() const
{
    return m_mathRepresentation;
}

GACubeGraphicRepresentation& GACube::GetGraphicsRepresentation() const
{
    return *m_graphicRepresentation;
}

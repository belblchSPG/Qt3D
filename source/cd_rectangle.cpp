#include "../headers/cd_rectangle.h"


GARectangle::GARectangle(const GARectangleMathRepresentation &math) :
    m_mathRepresentation(math) {}

GARectangleMathRepresentation GARectangle::GetMathRepresentation() const
{
    return m_mathRepresentation;
}

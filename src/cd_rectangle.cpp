#include "cd_rectangle.h"

namespace GA {


GARectangle::GARectangle(const GARectangleMathRepresentation &math) :
    m_mathRepresentation(math) {}

GARectangleMathRepresentation GARectangle::getMathRepresentation() const
{
    return m_mathRepresentation;
}

} // namespace GA

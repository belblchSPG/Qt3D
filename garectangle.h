#ifndef __GA_GARECTANGLE_H
#define __GA_GARECTANGLE_H

#include "GA.h"
#include "garectanglemathrepresentation.h"

using namespace GA;

namespace GA {

class GARectangle
{

private:

    GARectangleMathRepresentation m_mathRepresentation;

public:

    GARectangle() = delete;

    GARectangle(const GARectangleMathRepresentation &math);

    ~GARectangle() = default;

    //Метод возвращает математическое описание параллелепипеда
    GARectangleMathRepresentation getMathRepresentation() const;
};

} // namespace GA

#endif // __GA_GARECTANGLE_H

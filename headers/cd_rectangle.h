#ifndef __GA_GARECTANGLE_H__
#define __GA_GARECTANGLE_H__

#include "cd.h"
#include "../headers/cd_rectanglemathrepresentation.h"

class GARectangle
{

private:

    GARectangleMathRepresentation m_mathRepresentation;

public:

    GARectangle() = delete;

    GARectangle(const GARectangleMathRepresentation &math);

    ~GARectangle() = default;

    //Метод возвращает математическое описание параллелепипеда
    GARectangleMathRepresentation GetMathRepresentation() const;
};

#endif // __GA_GARECTANGLE_H__

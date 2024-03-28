#ifndef __CDDETECTOR_H__
#define __CDDETECTOR_H__

#include "cd.h"
#include "cd_contur.h"

class CDDetector
{
private:

    //Добавленыне в детектор контуры
    std::vector<CDContur*> m_geometry;

public:

    CDDetector() = default;

    ~CDDetector();

    //Добавление контура в детектор
    void AddGeom(CDContur* contur);

    //Добавление контура в детектор
    void AddGeom(std::vector<CDPoint> points);

    //Получение контуров из детектора
    std::vector<CDContur*> GetGeometry() const { return m_geometry; }

    //Расчет отношений между двумя контурами
    CDIntersectionResult ConturCollision(CDContur* c1, CDContur* c2) const;
};

#endif // CDDETECTOR_H__

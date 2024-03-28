#ifndef __CDCONTUR_H__
#define __CDCONTUR_H__

#include "cd.h"

class CDContur
{

private:

    //Точки, из которых состоит контур
    std::vector<CDPoint> m_points;

public:

    CDContur() = delete;

    ~CDContur();

    //Создание контура по трем точкам
    CDContur(CDPoint p1 ,CDPoint p2,CDPoint p3);

    //Создание контура из вектора точек
    CDContur(std::vector<CDPoint> points);

    //Получение точек, из которых состоит контур
    std::vector<CDPoint> GetPoints() const {return m_points;}

};



#endif // __CDCONTUR_H__

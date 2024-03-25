#ifndef __GACOLLISIONDETECTOR_H
#define __GACOLLISIONDETECTOR_H

#include "ga.h"
#include "gacube.h"
#include "garectangle.h"

using namespace GA;

namespace GA
{

//Класс, который будет выполнять проверку столкновений по данным об объектах, которые будут приходить в него
class GACollisionDetector
{
public:

    GACollisionDetector() = default;

    ~GACollisionDetector() = default;

    //Конструктор копирования
    GACollisionDetector(const GACollisionDetector& detector) = delete;

    //Оператор присваивания с копированием
    GACollisionDetector& operator=(const GACollisionDetector& copy) = delete;

    //Оператор присваивания с премещением
    GACollisionDetector& operator=(GACollisionDetector&& moved) = delete;

    //Метод возвращает список кортежей, в которых хранится информация о пересечении между каждым параллелепипедом на сцене
    //Кортеж хранит в себе указатели на параллелепипеды и тип пересечения данных параллелепипедов
    std::vector<std::tuple<GACube*,GACube*,GA::IntersectionType>> CollisionDetection3D(const std::vector<GACube*>&);

    std::vector<std::tuple<GARectangle*,GARectangle*,GA::IntersectionType>> CollisionDetection2D(const std::vector<GARectangle*>&);

    //Метод принимает два указателя на параллелепипеды и вовзращает тип пересечения между данными объектами
    GA::IntersectionType CalculateCollision3D(const GACube& cube1, const GACube& cube2);

    GA::IntersectionType CalculateCollision2D(const GARectangle& cube1, const GARectangle& cube2);
};
}
#endif // __GACOLLISIONDETECTOR_H

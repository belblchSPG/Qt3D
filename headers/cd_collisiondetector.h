#ifndef __GACOLLISIONDETECTOR_H__
#define __GACOLLISIONDETECTOR_H__

#include "cd.h"
#include "../headers/cd_cube.h"
#include "../headers/cd_rectangle.h"

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
    std::vector<std::tuple<GACube*,GACube*,CDIntersectionResult>> CollisionDetection3D(const std::vector<GACube*>&);

    std::vector<std::tuple<GARectangle*,GARectangle*,CDIntersectionResult>> CollisionDetection2D(const std::vector<GARectangle*>&);

    //Метод принимает два указателя на параллелепипеды и вовзращает тип пересечения между данными объектами
    CDIntersectionResult CalculateCollision3D(const GACube& cube1, const GACube& cube2);

    CDIntersectionResult CalculateCollision2D(const GARectangle& cube1, const GARectangle& cube2);
};
#endif // __GACOLLISIONDETECTOR_H__

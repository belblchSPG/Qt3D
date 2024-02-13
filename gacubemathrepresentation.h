#ifndef __GACUBEMATHREORESENTATION_H
#define __GACUBEMATHREORESENTATION_H

#include "GA.h"

using namespace GA;

namespace GA {

//Класс хранит параметры параллелепипеда, которое необходимо для его математического представления
class GACubeMathRepresentation
{
public:

    GACubeMathRepresentation() = default;

    //Конструктор принимает в себя координаты центра, размеры и углы поворота относительно каждый из осей параллелепипеда
    GACubeMathRepresentation(GA::Vector3D mathInfo[3]);

    ~GACubeMathRepresentation() = default;

    //Конструктор копирования
    GACubeMathRepresentation(const GACubeMathRepresentation& math) = default;

    //Конструктор перемещения
    GACubeMathRepresentation(GACubeMathRepresentation&& math) = delete;

    //Оператор присваивания с копированием
    GACubeMathRepresentation &operator=(const GACubeMathRepresentation& copy) = default;

    //Метод возвращает координаты центра параллелепипеда
    Point Center() const;

    //Метод возвращает ширину параллелепипеда
    double Width() const;

    //Метод возвращает высоту параллелепипеда
    double Height() const;

    //Метод возвращает длину параллелепипеда
    double Length() const;

    //Метод возвращает угол поворота параллелепипеда относительно оси X
    double XRot() const;

    //Метод возвращает угол поворота параллелепипеда относительно оси Y
    double YRot() const;

    //Метод возвращает угол поворота параллелепипеда относительно оси Z
    double ZRot() const;

    //Методы были необходимы для определения коллизий
    //Детектор коллизий не прошел тесты и его нужно будет переписать

    //Метод рассчитывает координаты всех вершин на основе хранимых данных и возвращает массив координат(точек)
    //std::vector<GA::Point> Vertices();

    ////Метод принимает вектор и кватернион и возвращает новый вектор, полученный в результате поворота полученного вектора на полученный кватернион
    //GA::Vector RotationVector(GA::Vector, GA::Quaternion);

    //std::vector<GA::Point> GetAxis(std::vector<GA::Point>, std::vector<GA::Point>);

private:

    //Поле хранит в себе координаты центра параллелепипеда
    GA::Point m_center = {0,0,0};

    //Поле хранит в себе размеры параллелепипеда
    GA::Size m_dimensions = {1,1,1};

    //Поле хранит углы поворота параллелепипеда относительно каждый оси
    GA::Rotation m_rotation = {0,0,0};
};
}
#endif // __MATHREPRESENTATION_H

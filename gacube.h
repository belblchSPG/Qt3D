#ifndef __GACUBE_H
#define __GACUBE_H

#include "GA.h"
#include "gacubemathrepresentation.h"
#include "gacubegraphicrepresentation.h"


using namespace GA;

namespace GA
{
//Класс, который отвечает за представление параллелепипеда на сцене.
//В нем хранится раздельное представление математики и графики объекта

class GACube
{

private:

    //Математическое описание параллелпипеда
    GACubeMathRepresentation m_mathRepresentation;

    //Графическое предаствление параллелепипеда на сцене
    GACubeGraphicRepresentation* m_graphicRepresentation;

public:

    GACube() = delete;

    //Конструктор, создающий экзмепляр параллелепипеда на основе принимаемого математического описания
    GACube(const GACubeMathRepresentation& math);

    //Кастомный деструктор
    ~GACube();

    //Конструктор копирования
    GACube(const GACube& cube) = delete;

    //Оператор присваивания с копированием
    GACube& operator=(const GACube& copy) = delete;

    //Оператор присваивания с премещением
    GACube& operator=(GACube&& moved) = delete;

    //Метод возвращает графическое представление параллелепипеда на сцене
    GACubeGraphicRepresentation& getGraphicsRepresentation() const;

    //Метод возвращает математическое описание параллелепипеда
    GACubeMathRepresentation getMathRepresentation() const;
};
}
#endif // __GACUBE_H
#ifndef __GACUBE_H
#define __GACUBE_H

#include "GA.h"
#include "gacubemathrepresentation.h"
#include "gacubegraphicrepresentation.h"


namespace GA
{
//Класс, который отвечает за представление параллелепипеда на сцене.
//В нем хранится раздельное представление математики и графики объекта

class GACube
{
private:

    //Математическое описание параллелпипеда
    GA::GACubeMathRepresentation m_mathRepresentation;

    //Графическое предаствление параллелепипеда на сцене
    GA::GACubeGraphicRepresentation* m_graphicRepresentation;

public:

    GACube() = delete;

    //Конструктор, создающий экзмепляр параллелепипеда на основе принимаемого математического описания
    GACube(const GACubeMathRepresentation& math);

    //Конструктор копирования
    GACube(const GACube& cube) = delete;

    //Оператор присваивания с копированием
    GACube& operator=(const GACube& copy) = delete;

    //Оператор присваивания с премещением
    GACube& operator=(GACube&& moved) = delete;

    //Кастомный деструктор
    ~GACube();

    //Метод возвращает указатель на графическое представление параллелепипеда на сцене
    GA::GACubeGraphicRepresentation& getGraphicsRepresentation() const;

    //Метод возвращает указатель на математическое описание параллелепипеда
    GA::GACubeMathRepresentation getMathRepresentation() const;
};
}
#endif // __GACUBE_H

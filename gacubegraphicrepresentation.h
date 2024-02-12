#ifndef __GACUBEGRAPHICREPRESENTATION_H
#define __GACUBEGRAPHICREPRESENTATION_H

#include "GA.h"
#include "gacubemathrepresentation.h"
#include "gascene.h"


namespace GA {

//Класс хранит информацию как будет отрисовываться параллелепипед на сцене
//Наследуется от сущности для того, чтобы не хранить дополнительное поле для сущноости, а использовать this
class GACubeGraphicRepresentation : public GA::Entity
{
public:

    GACubeGraphicRepresentation() = default;

    //Конструктор создает графическое представление параллелепипеда на основе математического описания
    GACubeGraphicRepresentation(const GA::GACubeMathRepresentation& math);

    //Конструктор копирования
    GACubeGraphicRepresentation(const GACubeGraphicRepresentation& graphic) = delete;

    //Конструктор перемещения
    GACubeGraphicRepresentation(GACubeGraphicRepresentation&& graphic) = delete;

    //Оператор присваивания с копированием
    GACubeGraphicRepresentation& operator=(const GACubeGraphicRepresentation& copy) = delete;

    //Кастомный деструктор
    ~GACubeGraphicRepresentation();

    //Метод возвращает ambient-цвет параллелепипеда
    GA::Color Color() const;

    //Метод заменяет нынешний ambient-цвет параллелепипеда на принимаемый
    void setColor(GA::Color color);

private:

    //Поле хранит указатель на меш параллелепипеда
    GA::CuboidMesh *m_mesh;

    //Поле хранит указатель на переменную, отвечающую за трехмерные преобразования параллелепипедаы
    GA::Transform *m_transform;

    //Поле хранит указатель на переменную, храняшую информацию о цвете параллелепипеда
    GA::DiffuseMaterial* m_material;
};
}
#endif // __GACUBEGRAPHICREPRESENTATION_H

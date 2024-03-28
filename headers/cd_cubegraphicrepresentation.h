#ifndef __GACUBEGRAPHICREPRESENTATION_H__
#define __GACUBEGRAPHICREPRESENTATION_H__

#include "cd.h"
#include "../headers/cd_cubemathrepresentation.h"
#include "../headers/cd_scene.h"

//Класс хранит информацию как будет отрисовываться параллелепипед на сцене
//Наследуется от сущности для того, чтобы не хранить дополнительное поле для сущноости, а использовать this
class GACubeGraphicRepresentation : public Entity
{
public:

    GACubeGraphicRepresentation() = default;

    //Конструктор создает графическое представление параллелепипеда на основе математического описания
    GACubeGraphicRepresentation(const GACubeMathRepresentation& math);

    //Кастомный деструктор
    ~GACubeGraphicRepresentation();

    //Конструктор копирования
    GACubeGraphicRepresentation(const GACubeGraphicRepresentation& graphic) = delete;

    //Конструктор перемещения
    GACubeGraphicRepresentation(GACubeGraphicRepresentation&& graphic) = delete;

    //Оператор присваивания с копированием
    GACubeGraphicRepresentation& operator=(const GACubeGraphicRepresentation& copy) = delete;

    //Метод возвращает ambient-цвет параллелепипеда
    QColor Color() const;

    //Метод заменяет нынешний ambient-цвет параллелепипеда на принимаемый
    void SetColor(QColor color);

private:

    //Поле хранит указатель на меш параллелепипеда
    CuboidMesh *m_mesh;

    //Поле хранит указатель на переменную, отвечающую за трехмерные преобразования параллелепипедаы
    Transform *m_transform;

    //Поле хранит указатель на переменную, храняшую информацию о цвете параллелепипеда
    DiffuseMaterial* m_material;
};
#endif // __GACUBEGRAPHICREPRESENTATION_H__

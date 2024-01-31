#ifndef GRAPHICREPRESENTATION_H
#define GRAPHICREPRESENTATION_H

#include "mathrepresentation.h"

#include <memory>
#include <QDiffuseSpecularMaterial>
#include <Qt3DExtras>

//Класс отвечает за графическое представление параллелепипеда
class GraphicRepresentation
{
public:
    GraphicRepresentation();
    GraphicRepresentation(MathRepresentation*, Qt3DCore::QEntity*);
    QColor Color() const;
    void setColor(QColor);

private:
    //Используется указатель, так как удаление может вызваться в любой момент времени
    std::unique_ptr<Qt3DCore::QEntity> parallelepipedEntity;
    //Используется указатель, так как цвет часто меняется во время пользования приложением
    std::unique_ptr<Qt3DExtras::QDiffuseSpecularMaterial> _material;
};

#endif // GRAPHICREPRESENTATION_H

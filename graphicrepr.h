#ifndef GRAPHICREPR_H
#define GRAPHICREPR_H

#include <QColor>

//Родительский класс, который хранит в себе цвет объекта на сцене
//Будет хранит в себе абстрактные методы для дочерних классов
class GraphicRepr
{
public:
    GraphicRepr();

    QColor Color();
    void setColor(QColor);

protected:
    QColor _color;
};

#endif // GRAPHICREPR_H

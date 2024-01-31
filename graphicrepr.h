#ifndef GRAPHICREPR_H
#define GRAPHICREPR_H

#include <QDiffuseSpecularMaterial>
#include <memory>

//Родительский класс, который хранит в себе цвет объекта на сцене
//Будет хранит в себе абстрактные методы для дочерних классов
class GraphicRepr
{
public:


protected:
    std::unique_ptr<Qt3DExtras::QDiffuseSpecularMaterial> _material;
};

#endif // GRAPHICREPR_H

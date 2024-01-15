#include "parallelepiped.h"

Parallelepiped::Parallelepiped() {}

Parallelepiped::Parallelepiped(float width, float height, float length, const QVector3D& center, Qt3DCore::QEntity* rootEntity) :
    _width(width), _height(height), _length(length), _center(center)
{

    try
    {
        if (width == 0 || height == 0 || length == 0)
        {
            throw std::invalid_argument("Invalid parallelepiped dimensions. Width, height, and length must be positive numbers.");
        }
        else
        {
            _mesh = new Qt3DExtras::QCuboidMesh();
            _mesh->setXExtent(_width);
            _mesh->setYExtent(_height);
            _mesh->setZExtent(_length);

            _parallelepipedMaterial = new Qt3DExtras::QDiffuseSpecularMaterial(rootEntity);
            _parallelepipedMaterial->setAmbient(Qt::blue);

            _parallelepipedTransform = new Qt3DCore::QTransform(rootEntity);

            // Позиция в пространстве
            _parallelepipedTransform->setTranslation(_center);

            // Масштаб фигуры
            _parallelepipedTransform->setScale(1.0);

            // Создаю сущность и добавляем в нее все компоненты
            _parallelepipedEntity = new Qt3DCore::QEntity(rootEntity);
            _parallelepipedEntity->addComponent(_mesh);
            _parallelepipedEntity->addComponent(_parallelepipedMaterial);
            _parallelepipedEntity->addComponent(_parallelepipedTransform);
        }
    }
    catch (const std::invalid_argument& e)
    {
        // Обработка ошибки
        qDebug() << "Error while creating parallelepiped:" << e.what();
        // Можно предпринять другие действия, например, установить значения по умолчанию или вывести пользователю предупреждение
    }
}

float Parallelepiped::Width() const
{
    return _width;
}

float Parallelepiped::Height() const
{
    return _height;
}

float Parallelepiped::Length() const
{
    return _length;
}

QVector3D Parallelepiped::Center() const
{
    return _center;
}

QColor Parallelepiped::getColor() const
{
    return _parallelepipedMaterial->ambient();
}

void Parallelepiped::SetColor(QColor color)
{
    _parallelepipedMaterial->setAmbient(color);
}

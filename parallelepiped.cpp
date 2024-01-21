#include "parallelepiped.h"


Parallelepiped::Parallelepiped(float width, float height, float length, QVector3D center, Qt3DCore::QEntity *rootEntity)
{
    try
    {
        if (width == 0 || height == 0 || length == 0)
        {
            throw std::invalid_argument("Invalid parallelepiped dimensions. Width, height, and length must be positive numbers.");
        }
        else
        {
            _parallMath = std::make_unique<MathParallRepr>(width, height, length, center);
            _parallGraphic = std::make_unique<GraphicParallRepr>(_parallMath.get(), rootEntity);
        }
    }
    catch (const std::invalid_argument& e)
    {
        // Обработка ошибки
        qDebug() << "Error while creating parallelepiped:" << e.what();
    }
}

GraphicParallRepr* Parallelepiped::GraphicsRepr() const
{
    return _parallGraphic.get();
}

MathParallRepr* Parallelepiped::MathRepr() const
{
    return _parallMath.get();
}

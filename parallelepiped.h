#ifndef PARALLELEPIPED_H
#define PARALLELEPIPED_H

#include <Qt3DExtras>
#include <Qt3DCore>

#include <QVector3D>
#include <QColor>
#include <stdexcept>

class Parallelepiped
{
public:
    Parallelepiped();
    Parallelepiped(float, float, float, const QVector3D&, Qt3DCore::QEntity*);

    float Width() const;
    float Height() const;
    float Length() const;
    QVector3D Center() const;
    QColor getColor() const;

    void SetColor(QColor);

private:
    float _width;
    float _height;
    float _length;
    QVector3D _center;

    Qt3DExtras::QCuboidMesh *_mesh;
    Qt3DExtras::QDiffuseSpecularMaterial *_parallelepipedMaterial;
    Qt3DCore::QTransform *_parallelepipedTransform;
    Qt3DCore::QEntity *_parallelepipedEntity;
};

#endif // PARALLELEPIPED_H

#ifndef SCENEMODIFIER_H
#define SCENEMODIFIER_H

#include <Qt3DExtras>
#include <QVector>
#include <QWidget>


class SceneModifier
{


public:
    SceneModifier(QWidget *parent = nullptr);

//Пересмотреть безопасность функции и усовершенствовать ее
    void GenerateTorus(float radius, float minor, int rings, int slices, Qt3DCore::QTransform *transform);


private:
    Qt3DCore::QEntity *m_rootEntity;
    QWidget *container;
    QVector<Qt3DCore::QEntity*> m_torusEntities;
    Qt3DExtras::QTorusMesh *m_torus;

};

#endif // SCENEMODIFIER_H

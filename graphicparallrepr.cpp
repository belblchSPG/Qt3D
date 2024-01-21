#include "graphicparallrepr.h"

GraphicParallRepr::GraphicParallRepr(MathParallRepr* repr, Qt3DCore::QEntity* rootEntity)
{
    //Форма объекта
    Qt3DExtras::QCuboidMesh *mesh = new Qt3DExtras::QCuboidMesh(rootEntity);
    mesh->setXExtent(repr->Width());
    mesh->setYExtent(repr->Height());
    mesh->setZExtent(repr->Length());

    //Материал объекта
    _material = std::make_unique<Qt3DExtras::QDiffuseSpecularMaterial>(rootEntity);

    //Расположение в пространстве и масштаб
    Qt3DCore::QTransform *transform = new Qt3DCore::QTransform(rootEntity);
    transform->setTranslation(repr->Center());
    transform->setScale(1.0);

    //Использовал выше операторы new, так как при добавлении компонентов я должен передавать указатели
    //В конструкторах передаю указатель на корневую сущность
    //Так как QEntity является наследником QObject, то при вызове дестрктора будут удаляться все ее дети.
    //Следовательно, при удалении сцены будут удаляться все указатели для представления графики параллелепипеда

    //Создаю сущность и добавляем в нее все компоненты
    //Передаю указатель на корневую сущность. Корневой сущностью будет являться указатель на сцену.
    Qt3DCore::QEntity *parallelepipedEntity = new Qt3DCore::QEntity(rootEntity);
    parallelepipedEntity->addComponent(mesh);
    parallelepipedEntity->addComponent(_material.get());
    parallelepipedEntity->addComponent(transform);
}



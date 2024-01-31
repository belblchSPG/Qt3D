#include "graphicrepresentation.h"

GraphicRepresentation::GraphicRepresentation()
{

}

GraphicRepresentation::GraphicRepresentation(MathRepresentation* mathRepr, Qt3DCore::QEntity *rootEntity)
{
    //Форма объекта
    Qt3DExtras::QCuboidMesh *mesh = new Qt3DExtras::QCuboidMesh(rootEntity);
    mesh->setXExtent(mathRepr->Width());
    mesh->setYExtent(mathRepr->Height());
    mesh->setZExtent(mathRepr->Length());

    //Материал объекта
    _material = std::make_unique<Qt3DExtras::QDiffuseSpecularMaterial>(rootEntity);
    _material.get()->setAmbient(Qt::gray);

    //Расположение в пространстве и масштаб
    Qt3DCore::QTransform *transform = new Qt3DCore::QTransform(rootEntity);
    transform->setTranslation(mathRepr->Center());

    qDebug() << mathRepr->XRot() <<mathRepr->YRot() <<mathRepr->ZRot();

    transform->setRotationX(mathRepr->XRot());
    transform->setRotationY(mathRepr->YRot());
    transform->setRotationZ(mathRepr->ZRot());

    //Использовал выше операторы new, так как при добавлении компонентов я должен передавать указатели
    //В конструкторах передаю указатель на корневую сущность
    //Так как QEntity является наследником QObject, то при вызове дестрктора будут удаляться все ее дети.
    //Следовательно, при удалении сцены будут удаляться все указатели для представления графики параллелепипеда

    //Создаю сущность и добавляем в нее все компоненты
    //Передаю указатель на корневую сущность. Корневой сущностью будет являться указатель на сцену.
    parallelepipedEntity = std::make_unique<Qt3DCore::QEntity>(rootEntity);
    parallelepipedEntity.get()->addComponent(mesh);
    parallelepipedEntity.get()->addComponent(_material.get());
    parallelepipedEntity.get()->addComponent(transform);
}

QColor GraphicRepresentation::Color() const
{
    return _material.get()->ambient();
}

void GraphicRepresentation::setColor(QColor color)
{
    _material.get()->setAmbient(color);
}

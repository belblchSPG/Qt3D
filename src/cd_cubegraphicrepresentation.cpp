#include "cd_cubegraphicrepresentation.h"

GACubeGraphicRepresentation::GACubeGraphicRepresentation(const GACubeMathRepresentation &math) :
    m_mesh(new GA::CuboidMesh),
    m_transform(new GA::Transform),
    m_material(new GA::DiffuseMaterial)
{
    //Привязываю графическое отображение к сцене, на которой буду отображать параллелепипед
    this->setParent(&GAScene::getRoot());

    //Придаю мешу необходимые габариты
    m_mesh->setXExtent(math.Width());
    m_mesh->setYExtent(math.Height());
    m_mesh->setZExtent(math.Length());

    //Придаю необходимый цвет
    m_material->setAmbient(Qt::gray);

    //Перемещаю объект в точку, где указан его центр. Поворачиваю объект на заданные углы относительно глоальных координат
    m_transform->setTranslation(math.Center());
    m_transform->setRotationX(math.XRot());
    m_transform->setRotationY(math.YRot());
    m_transform->setRotationZ(math.ZRot());

    //Добавляю к сущности все компоненты.
    this->addComponent(m_mesh);
    this->addComponent(m_material);
    this->addComponent(m_transform);
}

GACubeGraphicRepresentation::~GACubeGraphicRepresentation()
{
    //Убираю из сущности все компоненты
    this->removeComponent(this->m_material);
    this->removeComponent(this->m_mesh);
    this->removeComponent(this->m_transform);

    //Удаляю все хранящиеся указатели
    delete this->m_material;
    delete this->m_mesh;
    delete this->m_transform;
}

GA::Color GACubeGraphicRepresentation::Color() const
{
    return m_material->ambient();
}

void GACubeGraphicRepresentation::setColor(GA::Color color)
{
    m_material->setAmbient(color);
}

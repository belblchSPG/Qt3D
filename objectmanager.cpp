#include "objectmanager.h"

ObjectManager::ObjectManager()
{

}

ObjectManager::ObjectManager(Qt3DCore::QEntity * rootEntity)
{
    _rootEntity = rootEntity;
}

void ObjectManager::GenerateCuboidByLWHC(QVector<QVector<QLineEdit *> > vector)
{
    float width = vector[0][0]->text().toDouble();
    float height = vector[0][1]->text().toDouble();
    float length = vector[0][2]->text().toDouble();
    float x = vector[1][0]->text().toDouble();
    float y = vector[1][1]->text().toDouble();
    float z = vector[1][2]->text().toDouble();

    Parallelepiped *object = new Parallelepiped(width,height,length,QVector3D(x,y,z), _rootEntity);
    _objects.push_back(object);
}

std::vector<Parallelepiped*> ObjectManager::Objects() const
{
    return _objects;
}

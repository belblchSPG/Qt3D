#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include "parallelepiped.h"

#include <vector>
#include <QLineEdit>

//Класс, который будет отвечать за генерирование объектов на сцене
//и который будет хранить в себе все объекты
class ObjectManager
{
public:

    ObjectManager();
    ObjectManager(Qt3DCore::QEntity*);

    void GenerateCuboidByLWHC(QVector<QVector<QLineEdit*>>);
    std::vector<Parallelepiped*> Objects() const;

private:

    Qt3DCore::QEntity* _rootEntity;
    std::vector<Parallelepiped*> _objects;
};

#endif // OBJECTMANAGER_H

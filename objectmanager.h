#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include "parallelepiped.h"
#include "parser.h"
#include "collisiondetector.h"

#include <vector>
#include <tuple>
#include <algorithm>
#include <QLineEdit>
#include <QObject>

//Класс, который будет отвечать за генерирование объектов на сцене
//и который будет хранить в себе все объекты
class ObjectManager : public QObject
{
    Q_OBJECT
public:
    ObjectManager();

    ObjectManager(Qt3DCore::QEntity*);

    //void GenerateCuboidByLWHC(QVector<QVector<QLineEdit*>>);

    std::vector<Parallelepiped*> Objects() const;

    void GenerateObjectsFromFile(const QString& path);

    void deleteObject(Parallelepiped *object);

    void selectObject(Parallelepiped *object);

    void unselectObject(Parallelepiped *object);

    void showCollisions(std::vector<std::tuple<Parallelepiped*,Parallelepiped*,IntersectionType>>);

signals:

    void objectAdded(Parallelepiped *object);

private:

    Qt3DCore::QEntity* _rootEntity;

    std::vector<Parallelepiped*> _objects;
};

#endif // OBJECTMANAGER_H

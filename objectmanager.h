#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include "ga.h"
#include "gacube.h"
#include "parser.h"
#include "collisiondetector.h"


namespace GA{

//Класс, который будет отвечать за генерирование объектов на сцене
//и который будет хранить в себе все объекты
class ObjectManager : public QObject
{
    Q_OBJECT
public:
    ObjectManager();

    ObjectManager(Qt3DCore::QEntity*);

    //void GenerateCuboidByLWHC(QVector<QVector<QLineEdit*>>);

    std::vector<GA::GACube*> Objects() const;

    void GenerateObjectsFromFile(const QString& path);

    void deleteObject(GA::GACube *object);

    void selectObject(GA::GACube *object);

    void unselectObject(GA::GACube *object);

    void showCollisions(std::vector<std::tuple<GA::GACube*,GA::GACube*,GA::IntersectionType>>);

signals:

    void objectAdded(GA::GACube *object);

private:

    Qt3DCore::QEntity* _rootEntity;

    std::vector<GA::GACube*> _objects;
};

}
#endif // OBJECTMANAGER_H

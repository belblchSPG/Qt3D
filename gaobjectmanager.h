#ifndef __GAOBJECTMANAGER_H
#define __GAOBJECTMANAGER_H

#include "ga.h"
#include "gacube.h"
#include "gaparser.h"
#include "gacollisiondetector.h"

using namespace GA;

namespace GA{

//Класс, который будет отвечать за генерирование объектов на сцене
//и который будет хранить в себе все объекты
class GAObjectManager : public QObject
{
    Q_OBJECT
public:
    GAObjectManager();

    GAObjectManager(GA::Entity*);

    //void GenerateCuboidByLWHC(QVector<QVector<QLineEdit*>>);

    std::vector<GACube*> Objects() const;

    void GenerateObjectsFromFile(const GA::String& path);

    void deleteObject(GACube *object);

    void selectObject(GACube *object);

    void unselectObject(GACube *object);

    void showCollisions(std::vector<std::tuple<GACube*,GACube*,GA::IntersectionType>>);

signals:

    void objectAdded(GACube *object);

private:

    GA::Entity* m_rootEntity;

    std::vector<GACube*> m_objects;
};

}
#endif // __GAOBJECTMANAGER_H

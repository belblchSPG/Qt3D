#include "objectmanager.h"

GA::ObjectManager::ObjectManager()
{

}

GA::ObjectManager::ObjectManager(Qt3DCore::QEntity * rootEntity)
{
    _rootEntity = rootEntity;
}

//void ObjectManager::GenerateCuboidByLWHC(QVector<QVector<QLineEdit *> > vector)
//{
//    float width = vector[0][0]->text().toDouble();
//    float height = vector[0][1]->text().toDouble();
//    float length = vector[0][2]->text().toDouble();
//    float x = vector[1][0]->text().toDouble();
//    float y = vector[1][1]->text().toDouble();
//    float z = vector[1][2]->text().toDouble();
//
//    Parallelepiped *object = new Parallelepiped(width,height,length,QVector3D(x,y,z), _rootEntity);
//    _objects.push_back(object);
//
//    emit objectAdded(object);
//}

std::vector<GA::GACube*> GA::ObjectManager::Objects() const
{
    return _objects;
}

void GA::ObjectManager::GenerateObjectsFromFile(const QString &path)
{
    Parser parser;

    std::vector<GA::GACubeMathRepresentation> objectsToGenerate = parser.getInfo(path);

    for(const GA::GACubeMathRepresentation& a : objectsToGenerate)
    {
        GA::Vector3D mathInfo[3];

        mathInfo[0] = GA::Size(a.Width(),a.Height(),a.Length());
        mathInfo[1] = a.Center();
        mathInfo[2] = GA::Rotation(a.XRot(),a.YRot(),a.ZRot());

        GA::GACubeMathRepresentation math(mathInfo);

        GA::GACube *object = new GA::GACube(math);
        _objects.push_back(object);
        emit objectAdded(object);
    }
}

void GA::ObjectManager::deleteObject(GA::GACube *object)
{

    // Удаление объекта из вектора
    auto it = std::remove(_objects.begin(), _objects.end(), object);

    _objects.erase(it, _objects.end());

    delete object;
}

void GA::ObjectManager::selectObject(GA::GACube *object)
{
    object->getGraphicsRepresentation().setColor(Qt::green);
}

void GA::ObjectManager::unselectObject(GA::GACube *object)
{
    object->getGraphicsRepresentation().setColor(Qt::gray);
}

bool compareByIntersectionType(const std::tuple<GA::GACube*, GA::GACube*, GA::IntersectionType>& a,
                               const std::tuple<GA::GACube*, GA::GACube*, GA::IntersectionType>& b)
{
    return std::get<2>(a) < std::get<2>(b);
}

void GA::ObjectManager::showCollisions(std::vector<std::tuple<GA::GACube *, GA::GACube *, GA::IntersectionType>> collisions)
{

    std::sort(collisions.begin(), collisions.end(), compareByIntersectionType);

    for(int i = 0; i < collisions.size(); ++i)
    {
        qDebug() <<  std::get<0>(collisions.at(i)) << std::get<1>(collisions.at(i)) << std::get<2>(collisions.at(i));
    }

    for(size_t i = 0; i < collisions.size(); ++i)
    {
        if(std::get<1>(collisions.at(i)) == nullptr)
        {
            std::get<0>(collisions.at(i))->getGraphicsRepresentation().setColor(Qt::yellow);
            continue;
        }
        switch(std::get<2>(collisions.at(i)))
        {
            case IntersectionType::FullIntersection:
            {
                std::get<0>(collisions.at(i))->getGraphicsRepresentation().setColor(Qt::blue);
                std::get<1>(collisions.at(i))->getGraphicsRepresentation().setColor(Qt::blue);
                break;
            }
            case IntersectionType::PartialIntersection:
            {
                std::get<0>(collisions.at(i))->getGraphicsRepresentation().setColor(Qt::cyan);
                std::get<1>(collisions.at(i))->getGraphicsRepresentation().setColor(Qt::cyan);
                break;
            }
            case IntersectionType::SharedVertex:
            {
                std::get<0>(collisions.at(i))->getGraphicsRepresentation().setColor(QColor(170, 130, 140));
                std::get<1>(collisions.at(i))->getGraphicsRepresentation().setColor(QColor(170, 130, 140));
                break;
            }
            case IntersectionType::NoIntersection:
            {
                std::get<0>(collisions.at(i))->getGraphicsRepresentation().setColor(Qt::yellow);
                std::get<1>(collisions.at(i))->getGraphicsRepresentation().setColor(Qt::yellow);
                break;
            }
        }
    }
}


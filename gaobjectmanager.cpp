#include "gaobjectmanager.h"

GAObjectManager::GAObjectManager()
{

}

GAObjectManager::GAObjectManager(GA::Entity * rootEntity)
{
    m_rootEntity = rootEntity;
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

std::vector<GACube*> GAObjectManager::Objects() const
{
    return m_objects;
}

void GAObjectManager::GenerateObjectsFromFile(const GA::String &path)
{
    GAParser parser;

    std::vector<GACubeMathRepresentation> objectsToGenerate = parser.getInfo(path);

    for(const GACubeMathRepresentation& a : objectsToGenerate)
    {
        GA::Vector3D mathInfo[3];

        mathInfo[0] = GA::Size(a.Width(),a.Height(),a.Length());
        mathInfo[1] = a.Center();
        mathInfo[2] = GA::Rotation(a.XRot(),a.YRot(),a.ZRot());

        GACubeMathRepresentation math(mathInfo);

        GACube *object = new GACube(math);
        m_objects.push_back(object);
        emit objectAdded(object);
    }
}

void GAObjectManager::deleteObject(GACube *object)
{

    // Удаление объекта из вектора
    auto it = std::remove(m_objects.begin(), m_objects.end(), object);

    m_objects.erase(it, m_objects.end());

    delete object;
}

void GAObjectManager::selectObject(GACube *object)
{
    object->getGraphicsRepresentation().setColor(Qt::green);
}

void GAObjectManager::unselectObject(GACube *object)
{
    object->getGraphicsRepresentation().setColor(Qt::gray);
}

bool compareByIntersectionType(const std::tuple<GACube*, GACube*, GA::IntersectionType>& a,
                               const std::tuple<GACube*, GACube*, GA::IntersectionType>& b)
{
    return std::get<2>(a) < std::get<2>(b);
}

void GAObjectManager::showCollisions(std::vector<std::tuple<GACube *, GACube *, GA::IntersectionType>> collisions)
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
            case GA::IntersectionType::FullIntersection:
            {
                std::get<0>(collisions.at(i))->getGraphicsRepresentation().setColor(Qt::blue);
                std::get<1>(collisions.at(i))->getGraphicsRepresentation().setColor(Qt::blue);
                break;
            }
            case GA::IntersectionType::PartialIntersection:
            {
                std::get<0>(collisions.at(i))->getGraphicsRepresentation().setColor(Qt::cyan);
                std::get<1>(collisions.at(i))->getGraphicsRepresentation().setColor(Qt::cyan);
                break;
            }
            case GA::IntersectionType::SharedVertex:
            {
                std::get<0>(collisions.at(i))->getGraphicsRepresentation().setColor(QColor(170, 130, 140));
                std::get<1>(collisions.at(i))->getGraphicsRepresentation().setColor(QColor(170, 130, 140));
                break;
            }
            case GA::IntersectionType::NoIntersection:
            {
                std::get<0>(collisions.at(i))->getGraphicsRepresentation().setColor(Qt::yellow);
                std::get<1>(collisions.at(i))->getGraphicsRepresentation().setColor(Qt::yellow);
                break;
            }
        }
    }
}


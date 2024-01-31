#include "objectmanager.h"

ObjectManager::ObjectManager()
{

}

ObjectManager::ObjectManager(Qt3DCore::QEntity * rootEntity)
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

std::vector<Parallelepiped*> ObjectManager::Objects() const
{
    return _objects;
}

void ObjectManager::GenerateObjectsFromFile(const QString &path)
{
    Parser parser;
    std::vector<MathRepresentation> objectsToGenerate = parser.getInfo(path);
    for(auto a : objectsToGenerate)
    {
        qDebug() << a.Center() << a.Height() << a.Length() << a.Width() << a.XRot() << a.YRot() << a.ZRot();
        Parallelepiped *object = new Parallelepiped(a.Width(),a.Height(),a.Length(),a.Center(), a.XRot(),a.YRot(),a.ZRot(), _rootEntity);
        _objects.push_back(object);
        qDebug() << "Created : " << object;

        emit objectAdded(object);
    }
}

void ObjectManager::deleteObject(Parallelepiped *object)
{
    qDebug() << "Deleting : " << object;

    // Удаление объекта из вектора
    auto it = std::remove(_objects.begin(), _objects.end(), object);

    _objects.erase(it, _objects.end());

    delete object;
}

void ObjectManager::selectObject(Parallelepiped *object)
{
    object->GraphicsRepr()->setColor(Qt::green);
}

void ObjectManager::unselectObject(Parallelepiped *object)
{
    object->GraphicsRepr()->setColor(Qt::gray);
}

bool compareByIntersectionType(const std::tuple<Parallelepiped*, Parallelepiped*, IntersectionType>& a,
                               const std::tuple<Parallelepiped*, Parallelepiped*, IntersectionType>& b)
{
    return std::get<2>(a) < std::get<2>(b);
}

void ObjectManager::showCollisions(std::vector<std::tuple<Parallelepiped *, Parallelepiped *, IntersectionType>> collisions)
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
            std::get<0>(collisions.at(i))->GraphicsRepr()->setColor(Qt::yellow);
            continue;
        }
        switch(std::get<2>(collisions.at(i)))
        {
            case IntersectionType::FullIntersection:
            {
                std::get<0>(collisions.at(i))->GraphicsRepr()->setColor(Qt::blue);
                std::get<1>(collisions.at(i))->GraphicsRepr()->setColor(Qt::blue);
                break;
            }
            case IntersectionType::PartialIntersection:
            {
                std::get<0>(collisions.at(i))->GraphicsRepr()->setColor(Qt::cyan);
                std::get<1>(collisions.at(i))->GraphicsRepr()->setColor(Qt::cyan);
                break;
            }
            case IntersectionType::SharedVertex:
            {
                std::get<0>(collisions.at(i))->GraphicsRepr()->setColor(QColor(170, 130, 140));
                std::get<1>(collisions.at(i))->GraphicsRepr()->setColor(QColor(170, 130, 140));
                break;
            }
            case IntersectionType::NoIntersection:
            {
                std::get<0>(collisions.at(i))->GraphicsRepr()->setColor(Qt::yellow);
                std::get<1>(collisions.at(i))->GraphicsRepr()->setColor(Qt::yellow);
                break;
            }
        }
    }
}


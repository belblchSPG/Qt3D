#include "../headers/cd_objectmanager.h"

GAObjectManager::~GAObjectManager()
{
    for(int i = 0; i < m_objects.size(); ++i)
    {
        delete m_objects[i];
    }
    m_objects.clear();
}

std::vector<GACube*> GAObjectManager::Objects() const
{
    return m_objects;
}

void GAObjectManager::GenerateObjectsFromFile(const String &path)
{
    //Создаю парсер
    GAParser parser;

    //Создаю математические представляния на основе информации из файлов
    std::vector<GACubeMathRepresentation> objectsToGenerate = parser.GetInfo(path);

    //На базе полученных математических представлений создаю графическое представление объектов и добавляю объект на сцену
    for(const GACubeMathRepresentation& a : objectsToGenerate)
    {
        //Создаю объект
        GACube *object = new GACube(a);

        //Добавляю в список хранимых на сцене
        m_objects.push_back(object);

        //Генерирую сигнал о том, что добавился новый объект
        emit ObjectAdded(object);
    }
}

void GAObjectManager::DeleteObject(GACube *object)
{
    //Удаление объекта
    delete object;

    //Удаление объекта из вектора
    auto it = std::remove(m_objects.begin(), m_objects.end(), object);
    m_objects.erase(it, m_objects.end());   
}

void GAObjectManager::SelectObject(GACube *object)
{
    //При выборе объект меняет цвет на зеленый
    object->GetGraphicsRepresentation().SetColor(Qt::green);
}

void GAObjectManager::UnselectObject(GACube *object)
{
    //При отмене выбора цвет объекта меняется на серый
    object->GetGraphicsRepresentation().SetColor(Qt::gray);
}

//Сравнение типов необходимое для сортировки
bool compareByIntersectionType(const std::tuple<GACube*, GACube*, CDIntersectionResult>& a,
                               const std::tuple<GACube*, GACube*, CDIntersectionResult>& b)
{
    return std::get<2>(a) < std::get<2>(b);
}

void GAObjectManager::ShowCollisions(std::vector<std::tuple<GACube *, GACube *, CDIntersectionResult>> collisions)
{
    //Сортирую информацию о коллизиях в зависимости от типа коллизии
    //Самыми первыми идут пары объектов которые не имеют коллизий между собой
    //Далее идут пары с коллизиями
    std::sort(collisions.begin(), collisions.end(), compareByIntersectionType);

    for(int i = 0; i < collisions.size(); ++i)
    {
        qDebug() <<  std::get<0>(collisions.at(i)) << std::get<1>(collisions.at(i)) << std::get<2>(collisions.at(i));
    }

    //Изменение цвета объекта в зависимости от типа коллизии
    for(size_t i = 0; i < collisions.size(); ++i)
    {
        //Если в первой паре один из указателей нулевой, то это означает, что на сцене находится один объект
        //Этот объект окрашивается в желтый цвет
        if(std::get<1>(collisions.at(i)) == nullptr)
        {
            std::get<0>(collisions.at(i))->GetGraphicsRepresentation().SetColor(Qt::yellow);
            continue;
        }
        switch(std::get<2>(collisions.at(i)))
        {
            //При пересечении объектов они окрашиваются в синий
            case Intersection:
            {
                std::get<0>(collisions.at(i))->GetGraphicsRepresentation().SetColor(Qt::blue);
                std::get<1>(collisions.at(i))->GetGraphicsRepresentation().SetColor(Qt::blue);
                break;
            }
            //При отсутствии пересечений объекты окрашиваются в желтый
            case NoIntersection:
            {
                std::get<0>(collisions.at(i))->GetGraphicsRepresentation().SetColor(Qt::yellow);
                std::get<1>(collisions.at(i))->GetGraphicsRepresentation().SetColor(Qt::yellow);
                break;
            }
        }
    }
}

void GAObjectManager::ClearObjects()
{
    for(int i = 0; i < m_objects.size(); ++i)
    {
        delete m_objects[i];
    }
    m_objects.clear();
}


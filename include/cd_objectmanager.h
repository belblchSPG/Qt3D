#ifndef __GAOBJECTMANAGER_H
#define __GAOBJECTMANAGER_H

#include "ga.h"
#include "gacube.h"
#include "gaparser.h"
#include "gacollisiondetector.h"

using namespace GA;

namespace GA{

//Класс, который будет отвечать за хранение объектов на сцене и за
//взаимодействие с ними
class GAObjectManager : public QObject
{
    Q_OBJECT

public:

    GAObjectManager() = default;

    ~GAObjectManager();

    //Конструктор копирования
    GAObjectManager(const GAObjectManager& manager) = delete;

    //Оператор присваивания с копированием
    GAObjectManager& operator=(const GAObjectManager& copy) = delete;

    //Оператор присваивания с премещением
    GAObjectManager& operator=(GAObjectManager&& moved) = delete;

    //Метод возвращает список объектов, хранящихся на сцене
    std::vector<GACube*> Objects() const;

    //Метод принимает путь к файлу и генерирует объекты на основе информации из файла
    void GenerateObjectsFromFile(const GA::String& path);

    //Удаление объекта
    void deleteObject(GACube *object);

    //Выделение выбранного объекта
    void selectObject(GACube *object);

    //Отмена выделения объекта
    void unselectObject(GACube *object);

    //Окрашивание объектов в зависимости от их коллизий с другоими объектами
    void showCollisions(std::vector<std::tuple<GACube*,GACube*,GA::IntersectionType>>);

    //Метод удаляет все объекты со сцены
    void clearObjects();

signals:

    //Сигнал который генерируется при добавлении нового объекта
    void objectAdded(GACube *object);

private:

    //Объекты, находящиеся на сцене
    std::vector<GACube*> m_objects;
};
}
#endif // __GAOBJECTMANAGER_H

#ifndef __GAOBJECTMANAGER_H__
#define __GAOBJECTMANAGER_H__

#include "cd.h"
#include "../headers/cd_cube.h"
#include "../headers/cd_parser.h"
#include "../headers/cd_collisiondetector.h"

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
    void GenerateObjectsFromFile(const String& path);

    //Удаление объекта
    void DeleteObject(GACube *object);

    //Выделение выбранного объекта
    void SelectObject(GACube *object);

    //Отмена выделения объекта
    void UnselectObject(GACube *object);

    //Окрашивание объектов в зависимости от их коллизий с другоими объектами
    void ShowCollisions(std::vector<std::tuple<GACube*,GACube*,CDIntersectionResult>>);

    //Метод удаляет все объекты со сцены
    void ClearObjects();

signals:

    //Сигнал который генерируется при добавлении нового объекта
    void ObjectAdded(GACube *object);

private:

    //Объекты, находящиеся на сцене
    std::vector<GACube*> m_objects;
};
#endif // __GAOBJECTMANAGER_H__

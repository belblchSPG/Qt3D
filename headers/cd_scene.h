#ifndef __GASCENE_H__
#define __GASCENE_H__

#include "cd.h"
#include "../headers/cd_cube.h"
#include "../headers/cd_cameracontroller.h"
#include "../headers/cd_objectmanager.h"
#include "../headers/cd_collisiondetector.h"

//Класс, который хранит в себе сцену для отображения объектов
class GAScene : public QWidget
{
    Q_OBJECT

public:

    GAScene(QWidget* parent = nullptr);

    //Кастомный деструктор
    ~GAScene();

    //Конструктор копирования
    GAScene(const GAScene& scene) = delete;

    //Оператор присваивания с копированием
    GAScene& operator=(const GAScene& copy) = delete;

    //Оператор присваивания с премещением
    GAScene& operator=(GAScene&& moved) = delete;

    //Метод возвращает окно, в котором будут отображаться объекты
    Window3D& GetView();

    //Метод возвращает корневую сущность, при помощи которой к сцене будут привязываться необходимые элементы
    static Entity& GetRoot();

    //Метод возвращает список объектов, хранящихся на сцене
    std::vector<GACube*> GetObjects();

    //Метод обращается к своему менеджеру объектов и добавляется объекты из файла на сцену
    void OpenScene(const String& path);

    //Метод очищает сцену от объектов
    void ClearScene();

    //Метод обращается к своему менеджеру объектов и удаляет объект
    void DeleteObject(GACube* object);

    //Метод обращается к своему менеджеру объектов и выбирает объект
    void SelectObject(GACube* object);

    //Метод обращается к своему менеджеру объектов и отменяет выбор объекта
    void UnselectObject(GACube* object);

    //Метод обращается к своему менеджеру объектов и окрашивает объекты в зависимости от типа коллизий между объектами
    void ShowCollisions(std::vector<std::tuple<GACube*, GACube*, CDIntersectionResult>>);

private:

    //Храню статичную корневую сущность
    static Entity* m_rootEntity;

    //Менеджер объектов
    GAObjectManager* m_objectManager;

    //Окно для графического отображения сцены
    Window3D* m_view;

    //Метод для создания координатной плоскости на сцене
    Entity* CreateTransformedPlane(Entity* parent, Vector3D p0, Vector3D p1, Vector3D p3, Color color);

signals:
    //Сигнал, генерируемый при добавлении объекта на сцену
    void ObjectAddedToAppWindow(GACube* object);

public slots:
    //Слот для обработки добавления нового объекта
    void ObjectAdded(GACube* object);
};
#endif // __SCENE_H__

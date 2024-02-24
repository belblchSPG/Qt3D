#ifndef __GASCENE_H
#define __GASCENE_H

#include "GA.h"
#include "gacube.h"
#include "gacameracontroller.h"
#include "gaobjectmanager.h"
#include "gacollisiondetector.h"

using namespace GA;

namespace GA {

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
    GA::Window3D& getView();

    //Метод возвращает корневую сущность, при помощи которой к сцене будут привязываться необходимые элементы
    static GA::Entity& getRoot();

    //Метод возвращает список объектов, хранящихся на сцене
    std::vector<GACube*> getObjects();

    //Метод обращается к своему менеджеру объектов и добавляется объекты из файла на сцену
    void openScene(const GA::String& path);

    //Метод очищает сцену от объектов
    void clearScene();

    //Метод обращается к своему менеджеру объектов и удаляет объект
    void deleteObject(GACube* object);

    //Метод обращается к своему менеджеру объектов и выбирает объект
    void selectObject(GACube* object);

    //Метод обращается к своему менеджеру объектов и отменяет выбор объекта
    void unselectObject(GACube* object);

    //Метод обращается к своему менеджеру объектов и окрашивает объекты в зависимости от типа коллизий между объектами
    void showCollisions(std::vector<std::tuple<GACube*, GACube*, IntersectionType>>);

private:

    //Храню статичную корневую сущность
    static GA::Entity* m_rootEntity;

    //Менеджер объектов
    GAObjectManager* m_objectManager;

    //Окно для графического отображения сцены
    GA::Window3D* m_view;

    //Метод для создания координатной плоскости на сцене
    GA::Entity* createTransformedPlane(GA::Entity* parent, GA::Vector3D p0, GA::Vector3D p1, GA::Vector3D p3, GA::Color color);

signals:
    //Сигнал, генерируемый при добавлении объекта на сцену
    void objectAddedToAppWindow(GACube* object);

public slots:
    //Слот для обработки добавления нового объекта
    void objectAdded(GACube* object);
};
}
#endif // __SCENE_H

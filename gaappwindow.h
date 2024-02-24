#ifndef __GAAPPWINDOW_H
#define __GAAPPWINDOW_H

#include "GA.h"
#include "gascene.h"

#include <QMenu>
#include <QMenuBar>

using namespace GA;

namespace GA
{
//Класс отвечает за отображение приложения и его основных элементов
class GAAppWindow : public QMainWindow
{

public:

    //Конструктор, который принимает родительский виджет и добавляет его в иерархию приложения
    GAAppWindow(QWidget *parent = nullptr);

    ~GAAppWindow();

    //Конструктор копирования
    GAAppWindow(const GAAppWindow& app) = delete;

    //Оператор присваивания с копированием
    GAAppWindow& operator=(const GAAppWindow& copy) = delete;

    //Оператор присваивания с премещением
    GAAppWindow& operator=(GAAppWindow&& moved) = delete;

private:

    //Храню указатель на тулбар - обозреватель сцены, чтобы добавлять в него новые поля с добавляемыми объектами
    QToolBar *m_bar;
    //Храню указатель на сцену, чтобы иметь возможность графически отображать выбранный объект
    GAScene *m_scene;
    //Храню указатели на отображения объектов в обозревателе
    std::vector<QMenu*> m_menuObjects;

    //Метод вызывается в конструкторе для создания тулбара - обозревател сцены с отображением объектов на сцене
    QToolBar& generateSceneObserver();
    //Метод вызывается в конструкторе для создания главного меню бара
    QMenuBar& generateMenuBar();
    //Метод очищает обозреватель сцены
    void clearSceneObserver();

public slots:

    //Слот, который обрабатывает добавление каждого объекта на сцену и добавляет объект в обозреватель
    void handleObjectAddedInAppWindow(GACube *object);
};
}
#endif // __GAAPPWINDOW_H

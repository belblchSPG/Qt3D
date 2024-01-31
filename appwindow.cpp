#include "appwindow.h"

AppWindow::AppWindow(QWidget *parent)
    : QMainWindow{parent}
{
    _scene = new Scene(this);

    QWidget *container = createWindowContainer(_scene->getView(), this);

    this->setCentralWidget(container);

    this->setMenuBar(generateMenuBar());

    this->addToolBar(Qt::ToolBarArea::LeftToolBarArea,generateSceneObserver());

    connect(_scene, &Scene::objectAddedToAppWindow, this, &AppWindow::handleObjectAddedInAppWindow);
}

//Метод, который вызывается при нажатии на кнопку Open Scene в меню баре
void AppWindow::recieveFileName(const QString& path)
{
    _scene->OpenScene(path);
}

//Создание тулбара для отображения объектов на сцене
QToolBar* AppWindow::generateSceneObserver()
{
    _bar = new QToolBar(this);

    QLabel *title = new QLabel("Обозреватель сцены");

    _bar->addWidget(title);

    return _bar;
}


QMenuBar *AppWindow::generateMenuBar()
{
    QMenuBar *menuBar = new QMenuBar(this);

    QMenu *projectMenu = new QMenu("Project", this);

    QMenu *runMenu = new QMenu("Run", this);

    QAction *openSceneAction = new QAction("Open Scene", this);

    QAction *runDetectionAction = new QAction("Run",this);

    projectMenu->addAction(openSceneAction);

    menuBar->addAction(runDetectionAction);

    menuBar->addMenu(projectMenu);

    connect(openSceneAction, &QAction::triggered, this, [=](){
        QString fileName = QFileDialog::getOpenFileName(this, "Open File", "/home/", "Text Files (*.txt);;All Files (*.*)");
        this->recieveFileName(fileName);
    });

    connect(runDetectionAction, &QAction::triggered, this, [=](){
        CollisionDetector detector;
        _scene->showCollisions(detector.CollisionDetection(_scene->Objects()));
    });

    return menuBar;
}
//Слот, который обрабатывает добавление каждого объекта на сцену и добавляет объект в обозреватель
void AppWindow::handleObjectAddedInAppWindow(Parallelepiped* object)
{
    QMenuBar *objectMenuBar = new QMenuBar(this);

    QMenu *objectMenu = new QMenu("Object",objectMenuBar);

    QAction *deleteAction = new QAction("Delete Object", this);
    //Удалять объект по нажатию кнопки

    connect(deleteAction, &QAction::triggered, objectMenu, [=](){
        _scene->deleteObject(object);
        delete objectMenu;
    });

    connect(objectMenu, &QMenu::aboutToShow, this,[=](){
        _scene->selectObject(object);
    });

    connect(objectMenu, &QMenu::aboutToHide, this,[=](){
        _scene->unselectObject(object);
    });

    objectMenu->addAction(deleteAction);

    objectMenuBar->addMenu(objectMenu);

    _bar->addWidget(objectMenuBar);
}


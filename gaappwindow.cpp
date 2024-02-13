#include "gaappwindow.h"

GAAppWindow::GAAppWindow(QWidget *parent)
    : QMainWindow{parent}
{
    m_scene = new GAScene(this);

    QWidget *container = createWindowContainer(m_scene->getView(), this);

    this->setCentralWidget(container);

    this->setMenuBar(generateMenuBar());

    this->addToolBar(Qt::ToolBarArea::LeftToolBarArea,generateSceneObserver());

    connect(m_scene, &GAScene::objectAddedToAppWindow, this, &GAAppWindow::handleObjectAddedInAppWindow);
}

//Метод, который вызывается при нажатии на кнопку Open Scene в меню баре
void GAAppWindow::recieveFileName(const GA::String& path)
{
    m_scene->OpenScene(path);
}

//Создание тулбара для отображения объектов на сцене
QToolBar* GAAppWindow::generateSceneObserver()
{
    m_bar = new QToolBar(this);

    QLabel *title = new QLabel("Обозреватель сцены");

    m_bar->addWidget(title);

    return m_bar;
}


QMenuBar *GAAppWindow::generateMenuBar()
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
        GA::String fileName = QFileDialog::getOpenFileName(this, "Open File", "/home/", "Text Files (*.txt);;All Files (*.*)");
        this->recieveFileName(fileName);
    });

    connect(runDetectionAction, &QAction::triggered, this, [=](){
        GACollisionDetector detector;
        m_scene->showCollisions(detector.CollisionDetection(m_scene->Objects()));
    });

    return menuBar;
}
//Слот, который обрабатывает добавление каждого объекта на сцену и добавляет объект в обозреватель
void GAAppWindow::handleObjectAddedInAppWindow(GACube* object)
{
    QMenuBar *objectMenuBar = new QMenuBar(this);

    QMenu *objectMenu = new QMenu("Object",objectMenuBar);

    QAction *deleteAction = new QAction("Delete Object", this);
    //Удалять объект по нажатию кнопки

    connect(deleteAction, &QAction::triggered, objectMenu, [=](){
        m_scene->deleteObject(object);
        delete objectMenu;
    });

    connect(objectMenu, &QMenu::aboutToShow, this,[=](){
        m_scene->selectObject(object);
    });

    connect(objectMenu, &QMenu::aboutToHide, this,[=](){
        m_scene->unselectObject(object);
    });

    objectMenu->addAction(deleteAction);

    objectMenuBar->addMenu(objectMenu);

    m_bar->addWidget(objectMenuBar);
}


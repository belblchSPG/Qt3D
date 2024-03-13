#include "gaappwindow.h"

GAAppWindow::GAAppWindow(QWidget *parent)
    : QMainWindow{parent}
{
    //Создаю сцену для приложения
    m_scene = new GAScene(this);

    //Создаю контейнер к котором буду отображать сцену
    QWidget *container = createWindowContainer(&(m_scene->getView()), this);

    //Добавляю контейнер со сценой как центральный виджет
    this->setCentralWidget(container);

    //Добавляю меню бар
    this->setMenuBar(&generateMenuBar());

    //Добавляю тулбар, в котором будут отображаться объекты, находящиеся на сцене
    this->addToolBar(Qt::ToolBarArea::LeftToolBarArea, &generateSceneObserver());

    //Подписываюсь на то, что при добавлении нового объекта на сцену будет добавляться соответствующий ему элемент в обозреватель сцены
    connect(m_scene, &GAScene::objectAddedToAppWindow, this, &GAAppWindow::handleObjectAddedInAppWindow);

    this->showMaximized();
}

GAAppWindow::~GAAppWindow()
{
    //Удаляю указатель на обозреватель сцены
    delete m_bar;
    //Удаляю указатель на сцену
    delete m_scene;
}

QToolBar& GAAppWindow::generateSceneObserver()
{
    //Создаю сам обозреватель сцены
    m_bar = new QToolBar(this);

    //Добавляю ему заголовок
    QLabel *title = new QLabel("Обозреватель сцены");

    //Добавляю к нему заголовок
    m_bar->addWidget(title);

    return *m_bar;
}

QMenuBar& GAAppWindow::generateMenuBar()
{
    QMenuBar *menuBar = new QMenuBar(this);

    QMenu *projectMenu = new QMenu("Project", this);

    QAction *openSceneAction = new QAction("Open Scene", this);

    QAction *clearSceneAction = new QAction("Clear Scene", this);

    QAction *runDetectionAction = new QAction("Run",this);

    projectMenu->addAction(clearSceneAction);
    projectMenu->addAction(openSceneAction);

    menuBar->addAction(runDetectionAction);

    menuBar->addMenu(projectMenu);

    connect(openSceneAction, &QAction::triggered, this, [=](){
        GA::String filePath = QFileDialog::getOpenFileName(this, "Open File", "/home/", "Text Files (*.txt);;All Files (*.*)");
        m_scene->openScene(filePath);
    });

    connect(clearSceneAction, &QAction::triggered, this, [=](){
        m_scene->clearScene();
        clearSceneObserver();
    });

    connect(runDetectionAction, &QAction::triggered, this, [=](){
        GACollisionDetector detector;
        m_scene->showCollisions(detector.CollisionDetection3D(m_scene->getObjects()));
    });

    return *menuBar;
}

void GAAppWindow::clearSceneObserver()
{
    for(int i = 0; i < m_menuObjects.size(); ++i)
    {
        delete m_menuObjects[i];
    }
    m_menuObjects.clear();
}

void GAAppWindow::handleObjectAddedInAppWindow(GACube* object)
{
    //Создаю меню бар для хранения меню
    QMenuBar *objectMenuBar = new QMenuBar(this);

    //создаю меню для отображения объекта и возможности выбора действий, связанных с объектом
    QMenu *objectMenu = new QMenu("Object",objectMenuBar);

    //Создаю действие - удаление
    QAction *deleteAction = new QAction("Delete Object", this);

    //Добавляю в меню действий удаление объекта со сцены
    objectMenu->addAction(deleteAction);

    //Добавляю меню действий, которые можно сделать с объектом
    objectMenuBar->addMenu(objectMenu);

    m_menuObjects.push_back(objectMenu);

    //Добавляю отображение объекта в обозреватель сцены
    m_bar->addWidget(objectMenuBar);

    //Подписываюсь на удаление объекта
    //При нажатии на клавишу удаления объекта в сцене вызывается метод удаления объекта и в метод
    //передается указатель на удаляемый объект
    connect(deleteAction, &QAction::triggered, objectMenu, [=](){
        m_scene->deleteObject(object);
        delete objectMenu;
    });

    //Подписываюсь на выделение объекта при выборе
    //При выборе объекта в обозревателе зеленым цветом выделяется объект выбранный в обозревателе
    connect(objectMenu, &QMenu::aboutToShow, this, [=](){
        m_scene->selectObject(object);
    });

    //Подписываюсь на отмену выделения объекта
    //В момент когда пользователь прекращает взаимодействие с объектом в обозревателе выделение зеленым цветом прекращается
    connect(objectMenu, &QMenu::aboutToHide, this, [=](){
        m_scene->unselectObject(object);
    });
}

#include "scene.h"

Qt3DExtras::Qt3DWindow* createMainWindow(QWidget *parent);

Scene::Scene(QWidget *parent)
    : QWidget(parent)
{

    _rootEntity = std::make_unique<Qt3DCore::QEntity>();

    _objectManager = ObjectManager(_rootEntity.get());

    Qt3DExtras::Qt3DWindow* view = createMainScene(this);

    CameraController cameraController;

    cameraController.CreateCamera(view, _rootEntity.get());

    view->setRootEntity(_rootEntity.get());
}

// Вызываю данный метод для генерации кастомного окна для ввода данных
void Scene::Window_GenerateCuboidByLWHC()
{
    InputWindowLWHC *window = new InputWindowLWHC(this);

    qDebug() << "Created window ";

    // Когда из окна приходит сигнал resultReady на сцене вызывается метод GenerateCuboidByLWHC
    // Сигнал передает результаты в GenerateCuboidByLWHC
    connect(window, &InputWindowLWHC::resultReady, this, [=](){this->_objectManager.GenerateCuboidByLWHC(window->getResult());});

    window->show();
}

Qt3DExtras::Qt3DWindow *Scene::createMainScene(QWidget *parent)
{
    parent->setWindowTitle("Program");

    Qt3DExtras::Qt3DWindow *view = new Qt3DExtras::Qt3DWindow();

    //---------------------------Main Widget------------------------------//
    container = createWindowContainer(view,this);
    container->setMinimumSize(600,600);
    QVBoxLayout *layout = new QVBoxLayout(this);
    //--------------------------------------------------------------------//

    //---------------------------Tool Bar---------------------------------//
    QToolBar *tBar = new QToolBar(this);
    QToolButton *tRunButton = new QToolButton(this);
    QToolButton *tGenerateButton = new QToolButton(this);
    //tRunButton->setText("Run Algorithm");
    tRunButton->setIcon(QIcon(RUN_ICON_PATH));
    tGenerateButton->setText("Generate Cuboid");
    //--------------------------------------------------------------------//


    //---------------------------Generation Menu--------------------------//
    QMenu *tGenerateMenu = new QMenu(this);
    tGenerateButton->setMenu(tGenerateMenu);
    //--------------------------------------------------------------------//


    //---------------------------Actions----------------------------------//
    QAction *generate4LWHCAction = new QAction("Generate from sizes and center", this);
    //--------------------------------------------------------------------//

    //---------------------------Connect actions with menu----------------//
    tGenerateButton->setPopupMode(QToolButton::InstantPopup);
    tGenerateMenu->addAction(generate4LWHCAction);
    //--------------------------------------------------------------------//


    //---------------------------Open input window for generation action--------------------------//
    connect (generate4LWHCAction, &QAction::triggered, this, &Scene::Window_GenerateCuboidByLWHC);
    connect(tRunButton, &QToolButton::clicked, this, [=]() {
        CollisionDetector collisionDetector;
        collisionDetector.CollisionDetection(_objectManager.Objects());
    });
    //--------------------------------------------------------------------//


    //---------------------------Add widgets to tool bar----------------//
    tBar->addWidget(tRunButton);
    tBar->addWidget(tGenerateButton);
    //--------------------------------------------------------------------//


    //---------------------------Add widgets to main widget----------------//
    layout->addWidget(tBar);
    layout->addWidget(container);
    //--------------------------------------------------------------------//


    view->defaultFrameGraph()->setClearColor(QColor(QRgb(0x575757)));

    return view;
}

void Scene::resizeView(QSize size)
{
    container->resize(size);
}

void Scene::resizeEvent ( QResizeEvent * /*event*/ )
{
    resizeView(this->size());
}

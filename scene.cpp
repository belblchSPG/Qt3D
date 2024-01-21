#include "scene.h"

Qt3DExtras::Qt3DWindow* createMainWindow(QWidget *parent);

Scene::Scene(QWidget *parent)
    : QWidget(parent)
{

    _rootEntity = new Qt3DCore::QEntity();

    Qt3DExtras::Qt3DWindow* view = createMainWindow(this);

    createCamera(view);

    view->setRootEntity(_rootEntity);
}

void Scene::createCamera(Qt3DExtras::Qt3DWindow* view)
{
    Qt3DRender::QCamera *camera = view->camera();
    auto cameraEntity = view->camera();
    cameraEntity->setPosition(QVector3D(0, 0, 100.0f));
    cameraEntity->setUpVector(QVector3D(0, 1, 0));
    cameraEntity->setViewCenter(QVector3D(0, 0, 0));

    Qt3DExtras::QOrbitCameraController *cameraController = new Qt3DExtras::QOrbitCameraController(_rootEntity);
    cameraController->setCamera(camera);
    cameraController->setLookSpeed(180.0f);
    cameraController->setLinearSpeed(60.0f);

}

// Вызываю данный метод для генерации кастомного окна для ввода данных
void Scene::Window_GenerateCuboidByLWHC()
{
    InputWindowLWHC *window = new InputWindowLWHC(this);

    qDebug() << "Created window ";

    // Когда из окна приходит сигнал resultReady на сцене вызывается метод GenerateCuboidByLWHC
    // Сигнал передает в GenerateCuboidByLWHC QVector<float>
    connect(window, &InputWindowLWHC::resultReady, this, &Scene::GenerateCuboidByLWHC);

    window->show();
}

// В функцию приходит вектор значений, который будет парситься и в дальнейшем на основе полученных данных генерируется параллелепипед
void Scene::GenerateCuboidByLWHC(QVector<QVector<QLineEdit *>> vector)
{
    float width = vector[0][0]->text().toDouble();
    float height = vector[0][1]->text().toDouble();
    float length = vector[0][2]->text().toDouble();
    float x = vector[1][0]->text().toDouble();
    float y = vector[1][1]->text().toDouble();
    float z = vector[1][2]->text().toDouble();

    Parallelepiped *object = new Parallelepiped(width,height,length,QVector3D(x,y,z), _rootEntity);
    _sceneObjects.append(object);
}

void Scene::CollisionDetection()
{
    qDebug() << "Collision detection started";

    // Перебираем все кубоиды на сцене
    for (Parallelepiped* c1 : _sceneObjects)
    {
        // Перебираем остальные кубоиды для проверки пересечения
        for (Parallelepiped* c2 : _sceneObjects)
        {
            // Исключаем сравнение кубоидов с собой
            if (c1 != c2)
            {
                qDebug() << "Check " << c1 << "and " << c2;
                // Проверка на пересечение
                if (CheckCollision(c1, c2))
                {

                    c1->GraphicsRepr()->setColor(Qt::red);
                    c2->GraphicsRepr()->setColor(Qt::red);
                }
                else
                {
                    if(c1->GraphicsRepr()->Color()!=Qt::red)
                    {
                       c1->GraphicsRepr()->setColor(Qt::green);
                    }
                    if(c2->GraphicsRepr()->Color()!=Qt::red)
                    {
                       c2->GraphicsRepr()->setColor(Qt::green);
                    }
                }
            }
        }
    }
}

bool Scene::CheckCollision(Parallelepiped* p1, Parallelepiped* p2)
{
    // Проекции по осям
    bool overlapX = (p1->MathRepr()->Center().x() - p1->MathRepr()->Width()/2) <= (p2->MathRepr()->Center().x() + p2->MathRepr()->Width()/2) &&
                    (p1->MathRepr()->Center().x() + p1->MathRepr()->Width()/2) >= (p2->MathRepr()->Center().x() - p2->MathRepr()->Width()/2);

    bool overlapY = (p1->MathRepr()->Center().y() - p1->MathRepr()->Height()/2) <= (p2->MathRepr()->Center().y() + p2->MathRepr()->Height()/2) &&
                    (p1->MathRepr()->Center().y() + p1->MathRepr()->Height()/2) >= (p2->MathRepr()->Center().y() - p2->MathRepr()->Height()/2);

    bool overlapZ = (p1->MathRepr()->Center().z() - p1->MathRepr()->Length()/2) <= (p2->MathRepr()->Center().z() + p2->MathRepr()->Length()/2) &&
                    (p1->MathRepr()->Center().z() + p1->MathRepr()->Length()/2) >= (p2->MathRepr()->Center().z() - p2->MathRepr()->Length()/2);

    return overlapX && overlapY && overlapZ;
}

Qt3DExtras::Qt3DWindow *Scene::createMainWindow(QWidget *parent)
{
    parent->setWindowTitle("Program");

    Qt3DExtras::Qt3DWindow *view = new Qt3DExtras::Qt3DWindow();

    //---------------------------Main Widget------------------------------//
    container = createWindowContainer(view,this);
    container->setMinimumSize(600,600);
    QVBoxLayout *layout = new QVBoxLayout(this);
    //--------------------------------------------------------------------//

    //---------------------------Tool Bar---------------------------------//
    QToolBar *tBar = new QToolBar();
    QToolButton *tRunButton = new QToolButton();
    QToolButton *tGenerateButton = new QToolButton();
    //tRunButton->setText("Run Algorithm");
    tRunButton->setIcon(QIcon(RUN_ICON_PATH));
    tGenerateButton->setText("Generate Cuboid");
    //--------------------------------------------------------------------//


    //---------------------------Generation Menu--------------------------//
    QMenu *tGenerateMenu = new QMenu();
    tGenerateButton->setMenu(tGenerateMenu);
    //--------------------------------------------------------------------//


    //---------------------------Actions----------------------------------//
    QAction *generate4LWHCAction = new QAction("Generate from sizes and center", this);
    QAction *generate4VerticesAction = new QAction("Generate from 4 Vertices", this);
    //--------------------------------------------------------------------//

    //---------------------------Connect actions with menu----------------//
    tGenerateButton->setPopupMode(QToolButton::InstantPopup);
    tGenerateMenu->addAction(generate4VerticesAction);
    tGenerateMenu->addAction(generate4LWHCAction);
    //--------------------------------------------------------------------//


    //---------------------------Open input window for generation action--------------------------//
    connect (generate4LWHCAction, &QAction::triggered, this, &Scene::Window_GenerateCuboidByLWHC);
    connect(tRunButton, &QToolButton::clicked, this, &Scene::CollisionDetection);
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

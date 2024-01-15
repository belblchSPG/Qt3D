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
    qDebug() << "Collision detection started!";

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
                    qDebug() << "Colors changed red!";
                    c1->SetColor(Qt::red);
                    c2->SetColor(Qt::red);
                }
                else
                {
                    qDebug() << "Colors changed green!";
                    if(c1->getColor()!=Qt::red)
                    {
                       c1->SetColor(Qt::green);
                    }
                    if(c2->getColor()!=Qt::red)
                    {
                       c2->SetColor(Qt::green);
                    }

                }
            }
        }
    }
}

bool Scene::CheckCollision(Parallelepiped* p1, Parallelepiped* p2)
{

    // Проекции по осям
    bool overlapX = (p1->Center().x() - p1->Width()/2) <= (p2->Center().x() + p2->Width()/2) &&
                    (p1->Center().x() + p1->Width()/2) >= (p2->Center().x() - p2->Width()/2);

    bool overlapY = (p1->Center().y() - p1->Height()/2) <= (p2->Center().y() + p2->Height()/2) &&
                    (p1->Center().y() + p1->Height()/2) >= (p2->Center().y() - p2->Height()/2);

    bool overlapZ = (p1->Center().z() - p1->Length()/2) <= (p2->Center().z() + p2->Length()/2) &&
                    (p1->Center().z() + p1->Length()/2) >= (p2->Center().z() - p2->Length()/2);


    // Проверка наличия общих вершин
    bool commonVertices = (p1->Center() == p2->Center() + QVector3D(p2->Width()/2, p2->Height()/2, p2->Length()/2)) ||
                          (p2->Center() == p1->Center() + QVector3D(p1->Width()/2, p1->Height()/2, p1->Length()/2));

    // Проверка одного параллелепипеда внутри другого
    bool insideCheck = (p1->Center().x() - p1->Width()/2 >= p2->Center().x() - p2->Width()/2) &&
                       (p1->Center().x() + p1->Width()/2 <= p2->Center().x() + p2->Width()/2) &&
                       (p1->Center().y() - p1->Height()/2 >= p2->Center().y() - p2->Height()/2) &&
                       (p1->Center().y() + p1->Height()/2 <= p2->Center().y() + p2->Height()/2) &&
                       (p1->Center().z() - p1->Length()/2 >= p2->Center().z() - p2->Length()/2) &&
                       (p1->Center().z() + p1->Length()/2 <= p2->Center().z() + p2->Length()/2);

    if(overlapX)
    {
        qDebug() << "X";
    }
    if(overlapY)
    {
        qDebug() << "Y";
    }
    if(overlapZ)
    {
        qDebug() << "Z";
    }


    // Ваши дальнейшие действия в зависимости от результата проверок
    if (overlapX && overlapY && overlapZ) {
        return true;
    }
    if(commonVertices)
    {
        return true;
    }
    if(insideCheck)
    {
        return true;
    }
    return false;
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

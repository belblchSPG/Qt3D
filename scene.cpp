#include "scene.h"

Scene::Scene(QWidget *parent)
    : QWidget(parent)
{

    _rootEntity = std::make_unique<Qt3DCore::QEntity>();

    _objectManager = new ObjectManager(_rootEntity.get());

    connect(_objectManager, &ObjectManager::objectAdded, this, &Scene::objectAdded);

    _view = new Qt3DExtras::Qt3DWindow();

    _view->defaultFrameGraph()->setClearColor(QColor(QRgb(0x575757)));

    CameraController cameraController;

    cameraController.CreateCamera(_view, _rootEntity.get());

    // Плоскость XY (по умолчанию)
    createTransformedPlane(_rootEntity.get(), QVector3D(0.0f, 0.0f, 0.0f), QVector3D(10.0f, 0.0f, 0.0f), QVector3D(0.0f, 10.0f, 0.0f), Qt::green);
    createTransformedPlane(_rootEntity.get(), QVector3D(0.0f, 0.0f, 0.0f), QVector3D(0.0f, 10.0f, 0.0f), QVector3D(10, 0.0f, 0.0f), Qt::green);

    // Плоскость XZ
    createTransformedPlane(_rootEntity.get(), QVector3D(0.0f, 0.0f, 0.0f), QVector3D(10, 0.0f, 0.0f), QVector3D(0.0f, 0.0f, 10.0f), Qt::blue);
    createTransformedPlane(_rootEntity.get(), QVector3D(0.0f, 0.0f, 0.0f), QVector3D(0.0f, 0.0f, 10.0f), QVector3D(10, 0.0f, 0.0f), Qt::blue);

    // Плоскость YZ
    createTransformedPlane(_rootEntity.get(), QVector3D(0.0f, 0.0f, 0.0f), QVector3D(0.0f, 10.0f, 0.0f), QVector3D(0.0f, 0.0f, 10.0f), Qt::red);
    createTransformedPlane(_rootEntity.get(), QVector3D(0.0f, 0.0f, 0.0f), QVector3D(0.0f, 0.0f, 10.0f), QVector3D(0.0f, 10.0f, 0.0f), Qt::red);

    _view->setRootEntity(_rootEntity.get());
}

void Scene::OpenScene(const QString &path)
{
    _objectManager->GenerateObjectsFromFile(path);
}

Qt3DCore::QEntity *Scene::createTransformedPlane(Qt3DCore::QEntity *parent, QVector3D p0, QVector3D p1, QVector3D p3, QColor color) {
    // Векторы, образующие плоскость
    QVector3D v1 = p1 - p0;
    QVector3D v2 = p3 - p0;

    // Создание стандартной сетки в плоскости XZ
    Qt3DExtras::QPlaneMesh *planeMesh = new Qt3DExtras::QPlaneMesh();
    float wx = v1.length();
    float wz = v2.length();
    planeMesh->setWidth(wx);
    planeMesh->setHeight(wz);

    // Сущность плоскости
    Qt3DCore::QEntity *planeEntity = new Qt3DCore::QEntity(parent);
    // Добавление сетки к сущности
    planeEntity->addComponent(planeMesh);

    // Вычисление вектора нормали
    QVector3D n1 = QVector3D::crossProduct(v1, v2);

    // Определение матрицы поворота для выравнивания вектора нормали плоскости с вектором нормали сгенерированной плоскости (т.е. осью Y)
    QVector3D n2(0, 1, 0);
    QQuaternion rot = QQuaternion::rotationTo(n2, n1);

    // Теперь мы трансформируем вектор w1 (соответствующий вектору v1) в целевую плоскость
    QVector3D w1(-1, 0, 0);

    // Учтите: PlaneMesh создана в плоскости XZ, с нижней левой точкой в q0=(w/2, 0, -h/2)
    // Если пронумеровать против часовой стрелки, следующая точка - q1=(-w/2, 0, -h/2), и нормализованный вектор w1 между q0 и q1
    // равен w1=(-1, 0, 0)
    QVector3D w1Rotated = rot.rotatedVector(w1);

    // Теперь нам нужно вычислить матрицу поворота для выравнивания вектора w1 с вектором v1
    QQuaternion rot2 = QQuaternion::rotationTo(w1Rotated, v1);

    // Объединяем обе матрицы поворота (учтите порядок умножения матриц!)
    QQuaternion planeRotation = rot2 * rot;

    // Перенос к целевой якорной точке (центр плоскости)
    QVector3D transVec(0,0,0);

    // Создание трансформации
    Qt3DCore::QTransform *transform = new Qt3DCore::QTransform();
    transform->setTranslation(transVec);
    transform->setRotation(planeRotation);

    Qt3DExtras::QPhongAlphaMaterial *material = new Qt3DExtras::QPhongAlphaMaterial();
    material->setAlpha(.4);
    material->setAmbient(color);

    // И установка компонентов
    planeEntity->addComponent(transform);
    planeEntity->addComponent(material);

    return planeEntity;
}

void Scene::deleteObject(Parallelepiped *object)
{
    _objectManager->deleteObject(object);
}

void Scene::selectObject(Parallelepiped *object)
{
    _objectManager->selectObject(object);
}

void Scene::unselectObject(Parallelepiped *object)
{
    _objectManager->unselectObject(object);
}

std::vector<Parallelepiped *> Scene::Objects()
{
    return _objectManager->Objects();
}

void Scene::showCollisions(std::vector<std::tuple<Parallelepiped *, Parallelepiped *, IntersectionType> > collisions)
{
    _objectManager->showCollisions(collisions);
}

void Scene::objectAdded(Parallelepiped *object)
{
    // Передаем объект в AppWindow
    emit objectAddedToAppWindow(object);
}




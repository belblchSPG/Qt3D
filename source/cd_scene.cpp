#include "../headers/cd_scene.h"

Entity* GAScene::m_rootEntity = new Entity();

GAScene::GAScene(QWidget *parent)
    : QWidget(parent)
{

    m_objectManager = new GAObjectManager();

    connect(m_objectManager, &GAObjectManager::ObjectAdded, this, &GAScene::ObjectAdded);

    m_view = new Window3D();

    GACameraController cameraController;

    cameraController.CreateCamera(m_view);

    // Плоскость XY (по умолчанию)
    CreateTransformedPlane(m_rootEntity, Vector3D(0.0f, 0.0f, 0.0f), Vector3D(10.0f, 0.0f, 0.0f), Vector3D(0.0f, 10.0f, 0.0f), Qt::green);
    CreateTransformedPlane(m_rootEntity, Vector3D(0.0f, 0.0f, 0.0f), Vector3D(0.0f, 10.0f, 0.0f), Vector3D(10, 0.0f, 0.0f), Qt::green);

    // Плоскость XZ
    CreateTransformedPlane(m_rootEntity, Vector3D(0.0f, 0.0f, 0.0f), Vector3D(10, 0.0f, 0.0f), Vector3D(0.0f, 0.0f, 10.0f), Qt::blue);
    CreateTransformedPlane(m_rootEntity, Vector3D(0.0f, 0.0f, 0.0f), Vector3D(0.0f, 0.0f, 10.0f), Vector3D(10, 0.0f, 0.0f), Qt::blue);

    // Плоскость YZ
    CreateTransformedPlane(m_rootEntity, Vector3D(0.0f, 0.0f, 0.0f), Vector3D(0.0f, 10.0f, 0.0f), Vector3D(0.0f, 0.0f, 10.0f), Qt::red);
    CreateTransformedPlane(m_rootEntity, Vector3D(0.0f, 0.0f, 0.0f), Vector3D(0.0f, 0.0f, 10.0f), Vector3D(0.0f, 10.0f, 0.0f), Qt::red);

    m_view->setRootEntity(m_rootEntity);
}

GAScene::~GAScene()
{
    delete m_rootEntity;
    delete m_objectManager;
    delete m_view;
}

Window3D& GAScene::GetView()
{
    return *m_view;
}

void GAScene::OpenScene(const String &path)
{
    m_objectManager->GenerateObjectsFromFile(path);
}

void GAScene::ClearScene()
{
    m_objectManager->ClearObjects();
}

Entity *GAScene::CreateTransformedPlane(Entity *parent, Vector3D p0, Vector3D p1,Vector3D p3, QColor color) {

    // Векторы, образующие плоскость
    Vector3D v1 = p1 - p0;
    Vector3D v2 = p3 - p0;

    // Создание стандартной сетки в плоскости XZ
    Qt3DExtras::QPlaneMesh *planeMesh = new Qt3DExtras::QPlaneMesh();
    float wx = v1.length();
    float wz = v2.length();
    planeMesh->setWidth(wx);
    planeMesh->setHeight(wz);

    // Сущность плоскости
    Entity *planeEntity = new Entity(parent);
    // Добавление сетки к сущности
    planeEntity->addComponent(planeMesh);

    // Вычисление вектора нормали
    Vector3D n1 = Vector3D::crossProduct(v1, v2);

    // Определение матрицы поворота для выравнивания вектора нормали плоскости с вектором нормали сгенерированной плоскости (т.е. осью Y)
    Vector3D n2(0, 1, 0);
    Quaternion rot = Quaternion::rotationTo(n2, n1);

    // Теперь мы трансформируем вектор w1 (соответствующий вектору v1) в целевую плоскость
    Vector3D w1(-1, 0, 0);

    // Учтите: PlaneMesh создана в плоскости XZ, с нижней левой точкой в q0=(w/2, 0, -h/2)
    // Если пронумеровать против часовой стрелки, следующая точка - q1=(-w/2, 0, -h/2), и нормализованный вектор w1 между q0 и q1
    // равен w1=(-1, 0, 0)
    Vector3D w1Rotated = rot.rotatedVector(w1);

    // Теперь нам нужно вычислить матрицу поворота для выравнивания вектора w1 с вектором v1
    Quaternion rot2 = Quaternion::rotationTo(w1Rotated, v1);

    // Объединяем обе матрицы поворота (учтите порядок умножения матриц!)
    Quaternion planeRotation = rot2 * rot;

    // Перенос к целевой якорной точке (центр плоскости)
    QVector3D transVec(0,0,0);

    // Создание трансформации
    Transform *transform = new Transform();
    transform->setTranslation(transVec);
    transform->setRotation(planeRotation);

    Qt3DExtras::QPhongAlphaMaterial *material = new Qt3DExtras::QPhongAlphaMaterial();
    material->setAlpha(0.4f);
    material->setAmbient(color);

    // Установка компонентов
    planeEntity->addComponent(transform);
    planeEntity->addComponent(material);

    return planeEntity;
}

void GAScene::DeleteObject(GACube *object)
{
    m_objectManager->DeleteObject(object);
}

void GAScene::SelectObject(GACube *object)
{
    m_objectManager->SelectObject(object);
}

void GAScene::UnselectObject(GACube *object)
{
    m_objectManager->UnselectObject(object);
}

std::vector<GACube *> GAScene::GetObjects()
{
    return m_objectManager->Objects();
}

void GAScene::ShowCollisions(std::vector<std::tuple<GACube *, GACube *, CDIntersectionResult> > collisions)
{
    m_objectManager->ShowCollisions(collisions);
}

Entity &GAScene::GetRoot()
{
    return *m_rootEntity;
}

void GAScene::ObjectAdded(GACube *object)
{
    // Передаем объект в AppWindow
    emit ObjectAddedToAppWindow(object);
}

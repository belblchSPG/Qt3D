#include "gascene.h"

Entity* GAScene::m_rootEntity = new GA::Entity();

GAScene::GAScene(QWidget *parent)
    : QWidget(parent)
{

    m_objectManager = new GAObjectManager(m_rootEntity);

    connect(m_objectManager, &GAObjectManager::objectAdded, this, &GAScene::objectAdded);

    m_view = new GA::Window3D();

    m_view->defaultFrameGraph()->setClearColor(GA::Color(QRgb(0x575757)));

    GACameraController cameraController;

    cameraController.CreateCamera(m_view,m_rootEntity);

    // Плоскость XY (по умолчанию)
    createTransformedPlane(m_rootEntity, GA::Vector3D(0.0f, 0.0f, 0.0f), GA::Vector3D(10.0f, 0.0f, 0.0f), GA::Vector3D(0.0f, 10.0f, 0.0f), Qt::green);
    createTransformedPlane(m_rootEntity, GA::Vector3D(0.0f, 0.0f, 0.0f), GA::Vector3D(0.0f, 10.0f, 0.0f), GA::Vector3D(10, 0.0f, 0.0f), Qt::green);

    // Плоскость XZ
    createTransformedPlane(m_rootEntity, GA::Vector3D(0.0f, 0.0f, 0.0f), GA::Vector3D(10, 0.0f, 0.0f), GA::Vector3D(0.0f, 0.0f, 10.0f), Qt::blue);
    createTransformedPlane(m_rootEntity, GA::Vector3D(0.0f, 0.0f, 0.0f), GA::Vector3D(0.0f, 0.0f, 10.0f), GA::Vector3D(10, 0.0f, 0.0f), Qt::blue);

    // Плоскость YZ
    createTransformedPlane(m_rootEntity, GA::Vector3D(0.0f, 0.0f, 0.0f), GA::Vector3D(0.0f, 10.0f, 0.0f), GA::Vector3D(0.0f, 0.0f, 10.0f), Qt::red);
    createTransformedPlane(m_rootEntity, GA::Vector3D(0.0f, 0.0f, 0.0f), GA::Vector3D(0.0f, 0.0f, 10.0f), GA::Vector3D(0.0f, 10.0f, 0.0f), Qt::red);

    m_view->setRootEntity(m_rootEntity);
}

void GAScene::OpenScene(const GA::String &path)
{
    m_objectManager->GenerateObjectsFromFile(path);
}

GA::Entity *GAScene::createTransformedPlane(GA::Entity *parent, GA::Vector3D p0, GA::Vector3D p1, GA::Vector3D p3, GA::Color color) {
    // Векторы, образующие плоскость
    GA::Vector3D v1 = p1 - p0;
    GA::Vector3D v2 = p3 - p0;

    // Создание стандартной сетки в плоскости XZ
    Qt3DExtras::QPlaneMesh *planeMesh = new Qt3DExtras::QPlaneMesh();
    float wx = v1.length();
    float wz = v2.length();
    planeMesh->setWidth(wx);
    planeMesh->setHeight(wz);

    // Сущность плоскости
    GA::Entity *planeEntity = new GA::Entity(parent);
    // Добавление сетки к сущности
    planeEntity->addComponent(planeMesh);

    // Вычисление вектора нормали
    GA::Vector3D n1 = GA::Vector3D::crossProduct(v1, v2);

    // Определение матрицы поворота для выравнивания вектора нормали плоскости с вектором нормали сгенерированной плоскости (т.е. осью Y)
    GA::Vector3D n2(0, 1, 0);
    GA::Quaternion rot = GA::Quaternion::rotationTo(n2, n1);

    // Теперь мы трансформируем вектор w1 (соответствующий вектору v1) в целевую плоскость
    GA::Vector3D w1(-1, 0, 0);

    // Учтите: PlaneMesh создана в плоскости XZ, с нижней левой точкой в q0=(w/2, 0, -h/2)
    // Если пронумеровать против часовой стрелки, следующая точка - q1=(-w/2, 0, -h/2), и нормализованный вектор w1 между q0 и q1
    // равен w1=(-1, 0, 0)
    GA::Vector3D w1Rotated = rot.rotatedVector(w1);

    // Теперь нам нужно вычислить матрицу поворота для выравнивания вектора w1 с вектором v1
    GA::Quaternion rot2 = GA::Quaternion::rotationTo(w1Rotated, v1);

    // Объединяем обе матрицы поворота (учтите порядок умножения матриц!)
    GA::Quaternion planeRotation = rot2 * rot;

    // Перенос к целевой якорной точке (центр плоскости)
    QVector3D transVec(0,0,0);

    // Создание трансформации
    GA::Transform *transform = new GA::Transform();
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

void GAScene::deleteObject(GACube *object)
{
    m_objectManager->deleteObject(object);
}

void GAScene::selectObject(GACube *object)
{
    m_objectManager->selectObject(object);
}

void GAScene::unselectObject(GACube *object)
{
    m_objectManager->unselectObject(object);
}

std::vector<GACube *> GAScene::Objects()
{
    return m_objectManager->Objects();
}

void GAScene::showCollisions(std::vector<std::tuple<GACube *, GACube *, GA::IntersectionType> > collisions)
{
    m_objectManager->showCollisions(collisions);
}

void GAScene::objectAdded(GACube *object)
{
    // Передаем объект в AppWindow
    emit objectAddedToAppWindow(object);
}

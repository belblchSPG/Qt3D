#ifndef SCENE_H
#define SCENE_H

#include "inputwindowfv.h"
#include "inputwindowlwhc.h"
#include "parallelepiped.h"
#include "cameracontroller.h"
#include "objectmanager.h"
#include "collisiondetector.h"
#include "windowsmanager.h"

#include <Qt3DExtras>
#include <Qt3DCore>
#include <Qt3DRender>
#include <memory>
#include <QBuffer>
#include <QGraphicsOpacityEffect>
#include <vector>

//Класс, который хранит в себе сцену для отображения объектов
class Scene: public QWidget
{
    Q_OBJECT
private:

    std::unique_ptr<Qt3DCore::QEntity> _rootEntity;

    ObjectManager* _objectManager;

    Qt3DExtras::Qt3DWindow* _view;

public:
    Scene(QWidget *parent = nullptr);

    Qt3DExtras::Qt3DWindow* getView(){return _view;}

    void OpenScene(const QString& path);

    Qt3DCore::QEntity *createTransformedPlane(Qt3DCore::QEntity *parent, QVector3D p0, QVector3D p1, QVector3D p3, QColor color);

    void deleteObject(Parallelepiped *object);

    void selectObject(Parallelepiped *object);

    void unselectObject(Parallelepiped *object);

    std::vector<Parallelepiped*> Objects();

    void showCollisions(std::vector<std::tuple<Parallelepiped*,Parallelepiped*,IntersectionType>>);

signals:
    void objectAddedToAppWindow(Parallelepiped *object);

public slots:
    void objectAdded(Parallelepiped *object);
};

#endif // SCENE_H

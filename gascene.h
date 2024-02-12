#ifndef __GASCENE_H
#define __GASCENE_H

#include "GA.h"
#include "gacube.h"
#include "cameracontroller.h"
#include "objectmanager.h"
#include "collisiondetector.h"
#include "windowsmanager.h"


namespace GA {

//Класс, который хранит в себе сцену для отображения объектов
class GAScene : public QWidget
{
    Q_OBJECT
private:

    static GA::Entity* m_rootEntity;

    GA::ObjectManager* _objectManager;

    Qt3DExtras::Qt3DWindow* _view;

public:

    GAScene(QWidget* parent = nullptr);

    Qt3DExtras::Qt3DWindow* getView() { return _view; }

    void OpenScene(const QString& path);

    Qt3DCore::QEntity* createTransformedPlane(Qt3DCore::QEntity* parent, QVector3D p0, QVector3D p1, QVector3D p3, QColor color);

    void deleteObject(GA::GACube* object);

    void selectObject(GA::GACube* object);

    void unselectObject(GA::GACube* object);

    std::vector<GA::GACube*> Objects();

    void showCollisions(std::vector<std::tuple<GA::GACube*, GA::GACube*, GA::IntersectionType>>);

    static GA::Entity& getRoot() {return *m_rootEntity;}

signals:
    void objectAddedToAppWindow(GA::GACube* object);

public slots:
    void objectAdded(GA::GACube* object);
};
}
#endif // __SCENE_H

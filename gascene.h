#ifndef __GASCENE_H
#define __GASCENE_H

#include "GA.h"
#include "gacube.h"
#include "gacameracontroller.h"
#include "gaobjectmanager.h"
#include "gacollisiondetector.h"
#include "windowsmanager.h"

using namespace GA;

namespace GA {

//Класс, который хранит в себе сцену для отображения объектов
class GAScene : public QWidget
{
    Q_OBJECT
private:

    static GA::Entity* m_rootEntity;

    GAObjectManager* m_objectManager;

    GA::Window3D* m_view;

public:

    GAScene(QWidget* parent = nullptr);

    GA::Window3D* getView() { return m_view; }

    void OpenScene(const GA::String& path);

    GA::Entity* createTransformedPlane(GA::Entity* parent, GA::Vector3D p0, GA::Vector3D p1, GA::Vector3D p3, GA::Color color);

    void deleteObject(GACube* object);

    void selectObject(GACube* object);

    void unselectObject(GACube* object);

    std::vector<GACube*> Objects();

    void showCollisions(std::vector<std::tuple<GACube*, GACube*, IntersectionType>>);

    static GA::Entity& getRoot() {return *m_rootEntity;}

signals:
    void objectAddedToAppWindow(GACube* object);

public slots:
    void objectAdded(GACube* object);
};
}
#endif // __SCENE_H

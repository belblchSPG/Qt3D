#ifndef SCENE_H
#define SCENE_H

#include "inputwindowfv.h"
#include "inputwindowlwhc.h"
#include "parallelepiped.h"
#include "cameracontroller.h"
#include "objectmanager.h"
#include "collisiondetector.h"

#include <Qt3DExtras>
#include <Qt3DCore>
#include <Qt3DRender>
#include <QMenu>
#include <QToolBar>
#include <QToolButton>
#include <memory>

//Класс, который хранит в себе графическое отображение приложения
class Scene: public QWidget
{
private:

    std::unique_ptr<Qt3DCore::QEntity> _rootEntity;
    ObjectManager _objectManager;
    QWidget *container;

public:
    explicit Scene(QWidget *parent = nullptr);

    void Window_GenerateCuboidByLWHC();

    Qt3DExtras::Qt3DWindow* createMainScene(QWidget *parent);
protected:

    void
    resizeEvent ( QResizeEvent * event );

public slots:
    void
    resizeView(QSize size);
};

#endif // SCENE_H

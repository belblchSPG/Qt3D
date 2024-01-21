#ifndef SCENE_H
#define SCENE_H

#include "inputwindowfv.h"
#include "inputwindowlwhc.h"
#include "parallelepiped.h"

#include <Qt3DExtras>
#include <Qt3DCore>
#include <Qt3DRender>

#include <QMenu>
#include <QToolBar>
#include <QToolButton>

#define RUN_ICON_PATH "D:/Coding/Qt/Qt3D-Test/Icons/arrow-39-16.png"

class Scene: public QWidget
{
private:
    Qt3DCore::QEntity *_rootEntity;
    QWidget *container;
    QVector<Parallelepiped* > _sceneObjects;

public:
    explicit Scene(QWidget *parent = nullptr);

    void Window_GenerateCuboidByLWHC();
    void GenerateCuboidByLWHC(QVector<QVector<QLineEdit *>>);

    void CollisionDetection();
    bool CheckCollision(Parallelepiped*,Parallelepiped*);

    Qt3DExtras::Qt3DWindow* createMainWindow(QWidget *parent);
    void createCamera(Qt3DExtras::Qt3DWindow*);

protected:
    // reimplementation needed to handle resize events
    // http://doc.qt.io/qt-5/qwidget.html#resizeEvent
    void
    resizeEvent ( QResizeEvent * event );

public slots:
    void
    resizeView(QSize size);
};

#endif // SCENE_H

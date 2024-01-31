#ifndef APPWINDOW_H
#define APPWINDOW_H

#include "windowsmanager.h"
#include "scene.h"
#include "menubar.h"
#include "sceneobserver.h"

#include <memory>

#include <QMainWindow>
#include <QToolBar>

//Класс отвечает за отображение приложения
class AppWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit AppWindow(QWidget *parent = nullptr);
    void recieveFileName(const QString& path);
private:
    QToolBar *_bar;
    Scene *_scene;

    QToolBar *generateSceneObserver();
    QMenuBar *generateMenuBar();
public slots:
    void handleObjectAddedInAppWindow(Parallelepiped *object);
};

#endif // APPWINDOW_H

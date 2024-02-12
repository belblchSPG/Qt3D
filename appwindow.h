#ifndef APPWINDOW_H
#define APPWINDOW_H

#include "GA.h"
#include "windowsmanager.h"
#include "gascene.h"
#include "menubar.h"
#include "sceneobserver.h"


//Класс отвечает за отображение приложения
class AppWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit AppWindow(QWidget *parent = nullptr);
    void recieveFileName(const QString& path);
private:
    QToolBar *_bar;
    GA::GAScene *_scene;

    QToolBar *generateSceneObserver();
    QMenuBar *generateMenuBar();
public slots:
    void handleObjectAddedInAppWindow(GA::GACube *object);
};

#endif // APPWINDOW_H

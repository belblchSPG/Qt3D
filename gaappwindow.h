#ifndef __GAAPPWINDOW_H
#define __GAAPPWINDOW_H

#include "GA.h"
#include "windowsmanager.h"
#include "gascene.h"
#include "menubar.h"
#include "sceneobserver.h"

using namespace GA;

namespace GA
{

//Класс отвечает за отображение приложения
class GAAppWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit GAAppWindow(QWidget *parent = nullptr);
    void recieveFileName(const QString& path);
private:
    QToolBar *m_bar;
    GAScene *m_scene;

    QToolBar *generateSceneObserver();
    QMenuBar *generateMenuBar();
public slots:
    void handleObjectAddedInAppWindow(GACube *object);
};
}
#endif // __GAAPPWINDOW_H

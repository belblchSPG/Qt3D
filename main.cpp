#include "parallelepiped.h"
#include "scenemodifier.h"
#include "scene.h"

#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QMainWindow *w = new QMainWindow();

    Scene *scene = new Scene(w);

    scene->setMinimumSize(w->screen()->size());

    w->showMaximized();

    return app.exec();
}


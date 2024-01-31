#include "parallelepiped.h"
#include "scenemodifier.h"
#include "scene.h"
#include "appwindow.h"

#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    AppWindow *w = new AppWindow();

    w->showMaximized();

    return app.exec();
}


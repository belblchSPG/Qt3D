#include "../headers/cd_cube.h"
#include "../headers/cd_scene.h"
#include "../headers/cd_appwindow.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>


int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    GAAppWindow *w = new GAAppWindow();

    return app.exec();
}


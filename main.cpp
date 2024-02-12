#include "gacube.h"
#include "scenemodifier.h"
#include "gascene.h"
#include "appwindow.h"

#include <QApplication>
#include <QMainWindow>
#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    QApplication app(argc, argv);

    AppWindow *w = new AppWindow();

    w->showMaximized();

    //RUN_ALL_TESTS();

    return app.exec();
}


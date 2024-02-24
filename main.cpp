#include "GA.h"
#include "gacube.h"
#include "gascene.h"
#include "gaappwindow.h"

#include <QApplication>
#include <QMainWindow>
#include <gtest/gtest.h>

using namespace GA;

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    QApplication app(argc, argv);

    GAAppWindow *w = new GAAppWindow();

    w->showMaximized();

    //return RUN_ALL_TESTS();

    return app.exec();
}


#include "GA.h"
#include "gacube.h"
#include "gascene.h"
#include "cd_appwindow.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <gtest/gtest.h>

using namespace GA;

int main(int argc, char *argv[])
{
    int result = 0;

    QApplication app(argc, argv);

    GAAppWindow *w = new GAAppWindow();

#ifdef TESTING_MODE
    ::testing::InitGoogleTest(&argc, argv);
    result = RUN_ALL_TESTS();
#else
    result = app.exec();
#endif

    return result;
}

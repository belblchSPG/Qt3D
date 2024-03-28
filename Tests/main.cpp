#include "../headers/cd_cube.h"
#include "../headers/cd_scene.h"
#include "../headers/cd_appwindow.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <gtest/gtest.h>


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}


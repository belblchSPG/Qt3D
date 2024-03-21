cmake_minimum_required(VERSION 3.5)

project(Qt3DTest VERSION 0.1 LANGUAGES CXX)

if(MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
else()
    set(CMAKE_AUTOUIC ON)
    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTORCC ON)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()
find_package(Qt6 REQUIRED COMPONENTS Widgets 3DCore 3DExtras 3DLogic 3DInput 3DRender)

set(BUILD_MODE "Testing")

add_subdirectory(googletest)

if(BUILD_MODE STREQUAL "Application")
    set(PROJECT_SOURCES
        main.cpp
        cd_scene.h cd_scene.cpp
        cd_cube.h cd_cube.cpp
        cd_cameracontroller.h cd_cameracontroller.cpp
        cd_collisiondetector.h cd_collisiondetector.cpp
        cd_objectmanager.h cd_objectmanager.cpp
        cd_cubegraphicrepresentation.h cd_cubegraphicrepresentation.cpp
        cd_cubemathrepresentation.h cd_cubemathrepresentation.cpp
        cd_appwindow.h cd_appwindow.cpp
        cd_parser.h cd_parser.cpp
        ga.h
        cd_rectangle.h cd_rectangle.cpp
        cd_rectanglemathrepresentation.h cd_rectanglemathrepresentation.cpp
    )
endif()

if(BUILD_MODE STREQUAL "Testing")

    add_definitions(-DTESTING_MODE)

    set(PROJECT_SOURCES
        main.cpp
        cd_scene.h cd_scene.cpp
        cd_cube.h cd_cube.cpp
        cd_cameracontroller.h cd_cameracontroller.cpp
        cd_collisiondetector.h cd_collisiondetector.cpp
        cd_objectmanager.h cd_objectmanager.cpp
        cd_cubegraphicrepresentation.h cd_cubegraphicrepresentation.cpp
        cd_cubemathrepresentation.h cd_cubemathrepresentation.cpp
        cd_appwindow.h cd_appwindow.cpp
        cd_parser.h cd_parser.cpp
        ga.h
        cd_rectangle.h cd_rectangle.cpp
        cd_rectanglemathrepresentation.h cd_rectanglemathrepresentation.cpp

        cd.h
        cd_detector.h cd_detector.cpp
        cd_contur.h cd_contur.cpp

        tst_gacube.cpp
        tst_gacubemathrepresentation.cpp
        tst_collision2D.cpp
        tst_garectanglemathrepresentation.cpp
    )
endif()

add_executable(Qt3DTest
    ${PROJECT_SOURCES}
    cd_detector.h cd_detector.cpp
    cd_contur.h cd_contur.cpp
    cd.h
)

target_link_libraries(Qt3DTest PRIVATE
    Qt6::Widgets
    Qt6::3DExtras
    Qt6::3DLogic
    Qt6::3DCore
    Qt6::3DInput
    Qt6::3DRender
    GTest::gtest_main
)

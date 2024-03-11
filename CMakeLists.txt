cmake_minimum_required(VERSION 3.5)

project(Qt3D-Test VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Widgets 3DCore 3DExtras 3DLogic 3DInput 3DRender)

set(BUILD_MODE "Testing")

if(BUILD_MODE STREQUAL "Application")

    set(PROJECT_SOURCES
        main.cpp
        gascene.h gascene.cpp
        gacube.h gacube.cpp
        gacameracontroller.h gacameracontroller.cpp
        gacollisiondetector.h gacollisiondetector.cpp
        gaobjectmanager.h gaobjectmanager.cpp
        gacubegraphicrepresentation.h gacubegraphicrepresentation.cpp
        gacubemathrepresentation.h gacubemathrepresentation.cpp
        gaappwindow.h gaappwindow.cpp
        gaparser.h gaparser.cpp
        ga.h
    )
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Qt3D-Test
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
endif()

target_link_libraries(Qt3D-Test PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::3DExtras
    Qt${QT_VERSION_MAJOR}::3DLogic
    Qt${QT_VERSION_MAJOR}::3DCore
    Qt${QT_VERSION_MAJOR}::3DInput
    Qt${QT_VERSION_MAJOR}::3DRender
)
endif()

if(BUILD_MODE STREQUAL "Testing")

    add_definitions(-DTESTING_MODE)
    enable_testing()
    if ($ENV{GOOGLETEST_DIR})
        get_filename_component(_GTEST_BASE $ENV{GOOGLETEST_DIR} REALPATH)
    elseif (EXISTS "") # set by QC
        get_filename_component(_GTEST_BASE "" REALPATH) # set by QC
    endif()

    find_package(GTest REQUIRED)
    if (NOT GTest_FOUND)
        message (FATAL_ERROR "No GTest Found")
    endif()

    set(PROJECT_SOURCES
        main.cpp
        gascene.h gascene.cpp
        gacube.h gacube.cpp
        gacameracontroller.h gacameracontroller.cpp
        gacollisiondetector.h gacollisiondetector.cpp
        gaobjectmanager.h gaobjectmanager.cpp
        gacubegraphicrepresentation.h gacubegraphicrepresentation.cpp
        gacubemathrepresentation.h gacubemathrepresentation.cpp
        gaappwindow.h gaappwindow.cpp
        gaparser.h gaparser.cpp
        GA.h
        tst_gacube.cpp
        tst_gacubemathrepresentation.cpp
    )

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Qt3D-Test
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
endif()

target_link_libraries(Qt3D-Test PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::3DExtras
    Qt${QT_VERSION_MAJOR}::3DLogic
    Qt${QT_VERSION_MAJOR}::3DCore
    Qt${QT_VERSION_MAJOR}::3DInput
    Qt${QT_VERSION_MAJOR}::3DRender
    GTest::GTest
)

endif()

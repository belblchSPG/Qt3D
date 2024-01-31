cmake_minimum_required(VERSION 3.5)

project(Qt3D-Test VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Widgets 3DCore 3DExtras 3DLogic 3DInput 3DRender)

set(PROJECT_SOURCES
        main.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Qt3D-Test
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        scene.h scene.cpp

        inputwindowlwhc.h inputwindowlwhc.cpp
        parallelepiped.h parallelepiped.cpp

        #Icons/arrow-39-16.png
        #C:/Users/User/Downloads/arrow-39-16.png

        cameracontroller.h cameracontroller.cpp
        collisiondetector.h collisiondetector.cpp
        objectmanager.h objectmanager.cpp
        windowsmanager.h windowsmanager.cpp

        graphicrepresentation.h graphicrepresentation.cpp
        mathrepresentation.h mathrepresentation.cpp
        appwindow.h appwindow.cpp

        parser.h parser.cpp
)
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Qt3D-Test APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Qt3D-Test SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Qt3D-Test
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Qt3D-Test PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::3DExtras
    Qt${QT_VERSION_MAJOR}::3DLogic
    Qt${QT_VERSION_MAJOR}::3DCore
    Qt${QT_VERSION_MAJOR}::3DInput
    Qt${QT_VERSION_MAJOR}::3DRender
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Qt3D-Test)
endif()
set_target_properties(Qt3D-Test PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Qt3D-Test
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Qt3D-Test)
endif()



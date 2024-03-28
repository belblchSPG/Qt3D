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

if(BUILD_MODE STREQUAL "Testing")
    add_subdirectory(tests)
    add_subdirectory(googletest)
endif()

if(BUILD_MODE STREQUAL "DemoApp")
    add_subdirectory(source)
endif()

if(BUILD_MODE STREQUAL "Library")
    add_subdirectory(library)
endif()

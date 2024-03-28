file(GLOB_RECURSE TESTS_FILES "../tests/*.cpp")
file(GLOB_RECURSE INCLUDE_FILES "../headers/*.h")
file(GLOB_RECURSE SOURCE_FILES "../source/*.cpp")

# Исключаем main.cpp, который не относится к тестам, из списка файлов
list(FILTER SOURCE_FILES EXCLUDE REGEX ".*main.cpp$")

add_executable(Qt3DGTests
    ${SOURCE_FILES}
    ${INCLUDE_FILES}
    ${TESTS_FILES}
)

target_link_libraries(Qt3DGTests PRIVATE
    Qt6::Widgets
    Qt6::3DExtras
    Qt6::3DLogic
    Qt6::3DCore
    Qt6::3DInput
    Qt6::3DRender
    GTest::gtest_main
)

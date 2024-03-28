# Собираем все cpp файлы в директории source
file(GLOB_RECURSE SOURCE_FILES "../source/*.cpp")
file(GLOB_RECURSE INCLUDE_FILES "../headers/*.h")

# Создаем исполняемый файл для графического приложения
add_executable(Qt3DDemoApp
    ${SOURCE_FILES}
    ${INCLUDE_FILES}
)

# Линкуем библиотеки Qt
target_link_libraries(Qt3DDemoApp PRIVATE
    Qt6::Widgets
    Qt6::3DExtras
    Qt6::3DLogic
    Qt6::3DCore
    Qt6::3DInput
    Qt6::3DRender
)


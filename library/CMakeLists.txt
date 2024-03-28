# Собираем все cpp файлы в директории source
file(GLOB_RECURSE SOURCE_FILES "../source/*.cpp")
file(GLOB_RECURSE INCLUDE_FILES "../headers/*.h")

add_library(CD SHARED)

target_sources(CD PRIVATE
    ${SOURCE_FILES}
    ${INCLUDE_FILES}
)

# Линкуем библиотеки Qt
target_link_libraries(CD PRIVATE
    Qt6::Widgets
    Qt6::3DExtras
    Qt6::3DLogic
    Qt6::3DCore
    Qt6::3DInput
    Qt6::3DRender
)

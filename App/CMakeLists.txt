include_directories("${PROJECT_SOURCE_DIR}/external/include")
include_directories("${PROJECT_SOURCE_DIR}/engine")
include_directories("${PROJECT_SOURCE_DIR}/core")

add_subdirectory(parser)

add_library(
    framework
    framework.cpp
)

find_library(SDL2 NAMES "SDL2")
link_directories(${PROJECT_SOURCE_DIR}/engine)
link_directories(${PROJECT_SOURCE_DIR}/core)

add_executable(${PROJECT_NAME} game.cpp)

link_libraries(framework parser core engine)

target_link_libraries(${PROJECT_NAME} framework core engine parser ${SDL2} pthread)

target_compile_definitions(framework PUBLIC ASSETS_FOLDER="${PROJECT_SOURCE_DIR}/Assets")
target_compile_definitions(framework PUBLIC CONFIG_FOLDER="${PROJECT_SOURCE_DIR}/App/config")

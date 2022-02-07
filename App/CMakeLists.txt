include_directories("${PROJECT_SOURCE_DIR}/external/include")
include_directories("${PROJECT_SOURCE_DIR}/engine")
include_directories("${PROJECT_SOURCE_DIR}/core")

add_library(
    framework
    framework.cpp
)

find_library(SDL2 NAMES "SDL2")
link_directories(${PROJECT_SOURCE_DIR}/engine)
link_directories(${PROJECT_SOURCE_DIR}/core)

add_executable(${PROJECT_NAME} game.cpp)
target_link_libraries(${PROJECT_NAME} framework core engine ${SDL2} pthread)

cmake_minimum_required(VERSION 3.10.2)
set(PROJECT_NAME "AirHockey")
project(${PROJECT_NAME})

add_subdirectory(engine)
add_subdirectory(App)

include_directories("${PROJECT_SOURCE_DIR}/external/include")
include_directories("${PROJECT_SOURCE_DIR}/engine")

add_executable(${PROJECT_NAME} App/game.cpp)
target_link_libraries(${PROJECT_NAME} engine pthread)

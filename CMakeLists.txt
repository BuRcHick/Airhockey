cmake_minimum_required(VERSION 3.10.2)
set(PROJECT_NAME "AirHockey")
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(engine)
add_subdirectory(core)
add_subdirectory(App)

include_directories("${PROJECT_SOURCE_DIR}/external/include")
include_directories("${PROJECT_SOURCE_DIR}/engine")

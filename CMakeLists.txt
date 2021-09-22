cmake_minimum_required(VERSION 3.10.2)
set(PROJECT_NAME "AirHockey")
project(${PROJECT_NAME})
add_subdirectory(source)

include_directories("${PROJECT_SOURCE_DIR}/external/SDL/include")
include_directories("${PROJECT_SOURCE_DIR}/external/SDL_image")
include_directories("${PROJECT_SOURCE_DIR}/external/SDL_ttf")

SET(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")
SET(GCC_COVERAGE_LINK_FLAGS    "-lgcov")

add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

add_executable(${PROJECT_NAME} game.cpp)
target_link_libraries(${PROJECT_NAME} source pthread)
#target_link_directories(${PROJECT_NAME} source)

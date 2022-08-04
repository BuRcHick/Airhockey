cmake_minimum_required(VERSION 3.10.2)

set(PROJECT_NAME "AirHockey")
project(${PROJECT_NAME})

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Debug)
cmake_minimum_required(VERSION 3.5.1)

if(NOT MSVC AND NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

option(BUILD_SHARED_LIBS "Build the library as a shared library" OFF)
option(BUILD_SAMPLES "Build the SDL2_image sample program(s)" OFF)
option(SDL2IMAGE_SAMPLES "Build the SDL2_image sample program(s)" OFF)
option(SDL_STATIC_PIC "Static version of the library should be built with Position Independent Code" ON)
option(SUPPORT_OGG "Support loading OGG Vorbis music via libvorbis" ON)

add_subdirectory(external/libs/SDL2)
add_subdirectory(external/libs/SDL2_image)
add_subdirectory(external/libs/SDL2_ttf)
add_subdirectory(external/libs/xml)
add_subdirectory(engine)
add_subdirectory(core)
add_subdirectory(App)

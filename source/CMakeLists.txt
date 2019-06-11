
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
add_library(
    source
    libs/cwindow.hpp
    libs/cwindow.cpp
)
target_link_libraries(source ${SDL2_LIBRARIES})
target_include_directories(source PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/libs")
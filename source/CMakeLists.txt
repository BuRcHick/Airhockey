
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

add_library(
    source
    libs/cwindow.hpp
    libs/cwindow.cpp
    libs/cgameobj.hpp
    libs/cgameobj.cpp
    libs/cgame.hpp
    libs/cgame.cpp
)
target_link_libraries(source ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARY})
target_include_directories(source PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/libs")

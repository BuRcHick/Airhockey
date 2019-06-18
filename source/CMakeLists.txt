
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})
include_directories(${SDL2_TTF_INCLUDE_DIR})

add_library(
    source
    libs/cevent.hpp
    libs/cevent.cpp
    libs/cgameobj.hpp
    libs/cgameobj.cpp
    libs/ctext.hpp
    libs/ctext.cpp
    libs/сeventmanager.hpp
    libs/сeventmanager.cpp
    libs/cwindow.hpp
    libs/cwindow.cpp
    libs/cpreset.hpp
    libs/cpreset.cpp
    libs/cpresetmanager.hpp
    libs/cpresetmanager.cpp
    libs/cgame.hpp
    libs/cgame.cpp
)
target_link_libraries(source ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY})
target_include_directories(source PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/libs")
target_compile_definitions(source PUBLIC PICTURES_FOLDER="${CMAKE_CURRENT_SOURCE_DIR}/pictures")
target_compile_definitions(source PUBLIC FONTS_FOLDER="${CMAKE_CURRENT_SOURCE_DIR}/font")


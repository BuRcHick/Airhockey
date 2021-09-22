include_directories("${PROJECT_SOURCE_DIR}/external/SDL/include")
include_directories("${PROJECT_SOURCE_DIR}/external/SDL_image")
include_directories("${PROJECT_SOURCE_DIR}/external/SDL_ttf")

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

add_library(SDL2 SHARED IMPORTED)
set_property(TARGET SDL2 PROPERTY
    IMPORTED_LOCATION "${PROJECT_SOURCE_DIR}/external/SDL/build/.libs/libSDL2.so")

add_library(SDL2_image SHARED IMPORTED)
set_property(TARGET SDL2_image PROPERTY
    IMPORTED_LOCATION "${PROJECT_SOURCE_DIR}/external/SDL_image/.libs/libSDL2_image.so")

add_library(SDL2_ttf SHARED IMPORTED)
set_property(TARGET SDL2_ttf PROPERTY
    IMPORTED_LOCATION "${PROJECT_SOURCE_DIR}/external/SDL_ttf/.libs/libSDL2_ttf.so")

target_link_libraries(source SDL2 SDL2_image SDL2_ttf)

target_include_directories(source PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/libs")
target_compile_definitions(source PUBLIC PICTURES_FOLDER="${CMAKE_CURRENT_SOURCE_DIR}/pictures")
target_compile_definitions(source PUBLIC FONTS_FOLDER="${CMAKE_CURRENT_SOURCE_DIR}/font")


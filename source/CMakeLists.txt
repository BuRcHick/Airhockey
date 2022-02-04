include_directories("${PROJECT_SOURCE_DIR}/external/include")
include_directories("${PROJECT_SOURCE_DIR}/source/libs")
include_directories("${PROJECT_SOURCE_DIR}/engine")

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
    libs/cpreset.hpp
    libs/cpreset.cpp
    libs/cpresetmanager.hpp
    libs/cpresetmanager.cpp
    libs/cgame.hpp
    libs/cgame.cpp
)

find_library(SDL2 NAMES "SDL2")
find_library(SDL2_image NAMES "SDL2_image")
find_library(SDL2_ttf NAMES "SDL2_ttf")

message("SDL libraries ${SDL2} ${SDL2_image} ${SDL2_ttf}")

target_link_libraries(source ${SDL2} ${SDL2_image} ${SDL2_ttf})

target_compile_definitions(source PUBLIC PICTURES_FOLDER="${CMAKE_CURRENT_SOURCE_DIR}/pictures")
target_compile_definitions(source PUBLIC FONTS_FOLDER="${CMAKE_CURRENT_SOURCE_DIR}/font")

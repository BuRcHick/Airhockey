include_directories("${PROJECT_SOURCE_DIR}/external/include")
include_directories("${PROJECT_SOURCE_DIR}/engine")

add_library(
    engine
    logger/logger.cpp
    window/window.cpp
    texture/texture.cpp
    texture/texture_manager.cpp
    hitbox/hitbox_2d.cpp
)

find_library(SDL2 NAMES "SDL2")
find_library(SDL2_image NAMES "SDL2_image")
find_library(SDL2_ttf NAMES "SDL2_ttf")

message("SDL libraries ${SDL2} ${SDL2_image} ${SDL2_ttf}")

target_link_libraries(engine ${SDL2} ${SDL2_image} ${SDL2_ttf})

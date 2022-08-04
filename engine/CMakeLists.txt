include_directories("${PROJECT_SOURCE_DIR}/engine")

include_directories("${PROJECT_SOURCE_DIR}/external/libs/SDL2/include")
include_directories("${PROJECT_SOURCE_DIR}/external/libs/SDL2_image")
include_directories("${PROJECT_SOURCE_DIR}/external/libs/SDL2_ttf")
include_directories("${PROJECT_SOURCE_DIR}/external/libs/xml")

add_library(
    engine
    logger/logger.cpp
    window/window.cpp
    texture/texture.cpp
    texture/texture_manager.cpp
    hitbox/hitbox_2d.cpp
    xml/xml_loader.cpp
    vector/vector_2d.cpp
    point/point_2d.cpp
)

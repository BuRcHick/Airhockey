include_directories("${PROJECT_SOURCE_DIR}/external/include")
include_directories("${PROJECT_SOURCE_DIR}/engine")
include_directories("${PROJECT_SOURCE_DIR}/core")

add_library(
    core
    game_objects/game_object.cpp
    game_objects/physic_object.cpp
    game_objects/hockey_striker.cpp
    game_objects/hockey_puck.cpp
    event/event_manager.cpp
)

link_directories(${PROJECT_SOURCE_DIR}/engine)

target_link_libraries(core engine)

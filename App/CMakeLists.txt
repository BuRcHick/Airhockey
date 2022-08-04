include_directories("${PROJECT_SOURCE_DIR}/engine")
include_directories("${PROJECT_SOURCE_DIR}/core")

link_directories(${PROJECT_SOURCE_DIR}/engine)
link_directories(${PROJECT_SOURCE_DIR}/core)

include_directories("${PROJECT_SOURCE_DIR}/external/libs/SDL2/include")
include_directories("${PROJECT_SOURCE_DIR}/external/libs/SDL2_image")
include_directories("${PROJECT_SOURCE_DIR}/external/libs/SDL2_ttf")
include_directories("${PROJECT_SOURCE_DIR}/external/libs/xml")

add_subdirectory(parser)

add_library(
    framework
    framework.cpp
)

link_libraries(framework
        engine
        core
        parser
        SDL2::SDL2-static
        SDL2::SDL2main
        SDL2_image::SDL2_image-static
        SDL2_ttf::SDL2_ttf-static
        tinyxml2
)

if (WIN32)
    find_package(Threads)
    set(thread_lib Threads::Threads)
else()
    set(thread_lib pthread)
endif()

add_executable(${PROJECT_NAME} game.cpp)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        engine
        core
        parser
        framework
        ${thread_lib}
        SDL2::SDL2-static
        SDL2::SDL2main
        SDL2_image::SDL2_image-static
        SDL2_ttf::SDL2_ttf-static
        tinyxml2
)

target_compile_definitions(framework PUBLIC ASSETS_FOLDER="${PROJECT_SOURCE_DIR}/Assets")
target_compile_definitions(framework PUBLIC CONFIG_FOLDER="${PROJECT_SOURCE_DIR}/App/config")

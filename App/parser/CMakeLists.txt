include_directories("${PROJECT_SOURCE_DIR}/engine")

message("PIZDA!")

add_library(
    parser
    xml/config_parser.cpp
)

link_directories(${PROJECT_SOURCE_DIR}/engine)

link_libraries(parser engine)

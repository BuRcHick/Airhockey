include_directories("${PROJECT_SOURCE_DIR}/engine")
include_directories("${PROJECT_SOURCE_DIR}/external/libs/xml")

add_library(
    parser
    xml/config_parser.cpp
)

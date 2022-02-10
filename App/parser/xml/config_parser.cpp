#include "config_parser.hpp"
#include "logger/logger.hpp"

#include <cstring>

ConfigParser::ConfigParser()
    : m_config{0}
{
}

bool parseBordersParams(tinyxml2::XMLElement* element, Config& config, Config::Border& border)
{
    int width = config.global.width;
    int height = config.global.height;

    if (nullptr == element) {
        LOG_WARNING("Invalid input: element = %p\n", element);

        return false;
    }

    element = element->FirstChildElement();

    if (0 == strcmp("width", element->Name())) {
        border.width = element->IntText(width);
        element = element->NextSiblingElement();
    } else {
        border.width = width;
    }

    if (nullptr == element) {
        border.height = height;

        return false;
    }

    if (0 == strcmp("height", element->Name())) {
        border.height = element->IntText(height);
    } else {
        border.height = height;
    }

    return true;
}

bool parseBorders(tinyxml2::XMLElement* element, Config& config)
{
    int width = config.global.width;
    int height = config.global.height;

    if (nullptr == element) {
        LOG_WARNING("Invalid input: element = %p\n", element);

        return false;
    }

    if (0 == strcmp("top", element->Attribute("type"))) {
        parseBordersParams(element, config, config.scene.topBorder);
    } else if (0 == strcmp("bottom", element->Attribute("type"))) {
        parseBordersParams(element, config, config.scene.bottomBorder);
    } else if (0 == strcmp("left", element->Attribute("type"))) {
        parseBordersParams(element, config, config.scene.leftBorder);
    } else if (0 == strcmp("right", element->Attribute("type"))) {
        parseBordersParams(element, config, config.scene.rightBorder);
    }

    return true;
}

bool parseScene(tinyxml2::XMLElement* element, Config& config)
{
    if (nullptr == element) {
        LOG_WARNING("Invalid input: element = %p\n", element);

        return false;
    }

    while (element) {
        if (0 == strcmp("Border", element->Name())) {
            LOG_DEBUG("BORDER: %s\n", element->Name());
            parseBorders(element, config);
        }

        element = element->NextSiblingElement();
    }

    return true;
}

bool ConfigParser::parse()
{
    bool result = true;
    auto document = getDocument();
    tinyxml2::XMLElement* xml_config = document->RootElement();
    tinyxml2::XMLElement* element = xml_config->FirstChildElement();

    m_config.global.width = element->Int64Text();
    element = element->NextSiblingElement();
    m_config.global.height = element->Int64Text();

    element = element->NextSiblingElement();

    if (0 == strcmp("Scene", element->Name())) {
        element = element->FirstChildElement();
        result &= parseScene(element, m_config);
    }

    LOG_DEBUG("width: %d height: %d\n", m_config.global.width, m_config.global.height);

    return result;
}

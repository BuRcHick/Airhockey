#include "xml_loader.hpp"
#include "logger/logger.hpp"

#include <cstring>

XMLLoader::~XMLLoader()
{
    m_document.Clear();
}

bool XMLLoader::load(const char* path)
{
    tinyxml2::XMLError result = tinyxml2::XMLError::XML_SUCCESS;
    if (nullptr == path) {
        LOG_WARNING("Invalid input: path = %p\n", path);

        return false;
    }

    result = m_document.LoadFile(path);
    if (tinyxml2::XMLError::XML_SUCCESS != result) {
        LOG_ERROR("Failed to load %s config. Error = %d\n", path, result);

        return false;
    }

    return true;
}

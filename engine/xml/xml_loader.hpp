#ifndef __XML_LOADER_HPP__
#define __XML_LOADER_HPP__

#include "tinyxml2.h"

class XMLLoader {
public:
    XMLLoader() = default;
    virtual ~XMLLoader();

    bool load(const char* path);
    virtual bool parse() = 0;

protected:
    tinyxml2::XMLDocument* getDocument() { return &m_document; }

private:
    tinyxml2::XMLDocument m_document;
};

#endif /* __XML_LOADER_HPP__ */

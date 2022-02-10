#ifndef __CONFIG_PARSER_HPP__
#define __CONFIG_PARSER_HPP__

#include "xml/xml_loader.hpp"
#include "vector/vector_2d.hpp"

struct Config {
    struct Global {
        int height;
        int width;
    } global;

    struct Size {
        int width;
        int height;
    };

    struct Scene {
        Size topBorder;
        Size bottomBorder;
        Size leftBorder;
        Size rightBorder;
        Size hockeyPuck;
        Size hockeyStriker;
    } scene;
};

class ConfigParser : virtual public XMLLoader {
public:
    ConfigParser();
    virtual ~ConfigParser() {};

    virtual bool parse() override;
    Config const& getConfig() const { return m_config; };

private:
    Config m_config;
};

#endif /* __CONFIG_PARSER_HPP__ */

#ifndef __CONFIG_PARSER_HPP__
#define __CONFIG_PARSER_HPP__

#include "xml/xml_loader.hpp"
#include "vector/vector_2d.hpp"

struct Config {
    struct Global {
        int height;
        int width;
    } global;

    struct Border {
        int width;
        int height;
    };

    struct Scene {
        Border topBorder;
        Border bottomBorder;
        Border leftBorder;
        Border rightBorder;
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

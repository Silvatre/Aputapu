#pragma once
 
#include <SFML/Graphics.hpp>
#include "ResourceManager.h"
 
class FontManager : public ResourceManager< sf::Font > {
private:
protected:
    virtual sf::Font* load( const std::string& strId );
public:
};
 
extern FontManager gFontManager;
#include <iostream>
#include "FontManager.h"
 
using namespace std;
 
FontManager gFontManager;
 
sf::Font* FontManager::load( const std::string& strId ) {
    sf::Font* font = new sf::Font;
    if( !font->LoadFromFile( strId ) ) {
        cout << "[WARN] ImageManager failed to load: " << strId << endl;
        delete font;
        font = NULL;
    }
    return font;
}
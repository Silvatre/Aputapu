#pragma once
 
#include <SFML/Graphics.hpp>
#include "AnimatedButton.h"
#include "ResourceManager.h"
 
class ButtonManager : public ResourceManager< sf::AnimatedButton > {
private:
protected:
	virtual sf::AnimatedButton* load( const std::string& strId );
public:
	sf::AnimatedButton& AddResource( sf::AnimatedButton& newResource, const std::string& strId );
	sf::AnimatedButton& getResource( const std::string& strId );
};

extern ButtonManager gButtonManager;
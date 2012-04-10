#pragma once
#include <SFML/Graphics.hpp>

class CustomCursor: public sf::Sprite
{
	sf::RenderWindow* myWindow;
public:
	CustomCursor();
	CustomCursor(const sf::Image &Img, sf::RenderWindow* toAdd): myWindow(toAdd) { this->Sprite::Sprite(Img); }
	~CustomCursor();
	void Update();
	void Draw(sf::RenderTarget& Target) const;
};
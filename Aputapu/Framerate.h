#pragma once
#include <SFML/Graphics.hpp>

namespace sf{

class FramesPerSecond: public sf::String
{
	sf::Clock Clock;
	char* Framerate;
	double RefreshRate;		// Refresh rate in seconds.
	double LastRefresh;		// Last refresh time in seconds. Value 0 enables drawing.
public:
	FramesPerSecond();
	~FramesPerSecond();
	void Update();
	void Draw(sf::RenderTarget& Target);
};

} // namespace sf
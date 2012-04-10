#include <SFML/Graphics.hpp>
#include "GameplayController.h"

int main()
{
	// Initialize main window
	sf::RenderWindow App(sf::VideoMode(1024, 768, 32), "Aputapu", sf::Style::Close);
	// Set-up options
	App.UseVerticalSync(true);
	App.ShowMouseCursor(false);
	// Load gameplay configuration and start game
	gFontManager.getResource("Data/Resources/arial.ttf");	// Frequently used font loaded to manager
	GameplayConfiguration Config(&gButtonManager, &gImageManager);
	GameplayController Aputapu(&App);
	Aputapu.StartGame();
    return EXIT_SUCCESS;
}

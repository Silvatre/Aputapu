#pragma once

#include <SFML/Graphics.hpp>
#include "GameoverView.h"
#include "GameplayConfiguration.h"
#include "Cursor.h"
#include "Level.h"

extern ImageManager gImageManager;
extern ButtonManager gButtonManager;
extern FontManager gFontManager;

class GameoverController
{
	sf::RenderWindow* App;
	GameoverView* View;

	sf::Sprite Background;
	Ball YesButton;
	Ball NoButton;
	CustomCursor& Cursor;
	Level& GameLevel;
public:
	GameoverController(sf::RenderWindow* ptrWin, Level& refLvl, CustomCursor& refCursor): App(ptrWin), GameLevel(refLvl), Cursor(refCursor)
	{
		YesButton.SetColor(Ball::Green);
		NoButton.SetColor(Ball::Red);
		Background.SetImage(*gImageManager.getResource("Data/Resources/Gameover.png"));
		View = new GameoverView(GameLevel, Cursor, Background, YesButton, NoButton);
	}
	~GameoverController() {
		delete View;
	}
	bool PlayAgain();
};
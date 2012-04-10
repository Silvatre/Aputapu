#pragma once

#include <SFML/Graphics.hpp>
#include "GameplayView.h"
#include "GameplayConfiguration.h"
#include "Cursor.h"
#include "Selection.h"
#include "Level.h"
#include "Countdown.h"


extern ImageManager gImageManager;
extern ButtonManager gButtonManager;
extern FontManager gFontManager;

class GameplayController
{
	sf::RenderWindow* App;
	GameplayView* View;

	sf::Sprite Background;
	CustomCursor Cursor;
	Level GameLevel;
	Countdown<int> myCountdown;
	bool myPlaying;
public:
	GameplayController(sf::RenderWindow*);
	~GameplayController() {
		delete View;
	}
	void StartGame();
	void RestartGame();
	void EndGame();
};
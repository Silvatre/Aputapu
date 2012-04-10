#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "BallsCollection.h"
#include "Framerate.h"
#include "Cursor.h"
#include "Level.h"
#include "Countdown.h"

class GameplayView
{
	/*/ References to models that view is using /*/
	Level& GameLevel;
	CustomCursor& Cursor;
	sf::Sprite& Background;
	Countdown<int>& myCountdown;
	/*/ Strings that will display models data in current view's specific way /*/
	sf::String mySelectedBallsDisplay;
	sf::String myLevelDisplay;
	sf::String myMaxStreakDisplay;
	sf::String myPointsDisplay;
	sf::String myCountdownDisplay;
public:
	GameplayView(Level& refLevel, CustomCursor& refCursor, sf::Sprite& refBg, Countdown<int>& refCount): GameLevel(refLevel), Cursor(refCursor), Background(refBg), myCountdown(refCount)
	{
		/*/ Setting up how the view will display data /*/
		mySelectedBallsDisplay.SetFont(*gFontManager.getResource("Data/Resources/arial.ttf"));
		mySelectedBallsDisplay.SetPosition(581, 713);
		mySelectedBallsDisplay.SetSize(15);
		mySelectedBallsDisplay.SetStyle(sf::String::Bold);

		myLevelDisplay.SetFont(*gFontManager.getResource("Data/Resources/arial.ttf"));
		myLevelDisplay.SetPosition(366, 590);
		myLevelDisplay.SetSize(15);
		myLevelDisplay.SetStyle(sf::String::Bold);
		myLevelDisplay.SetColor(sf::Color(132, 199, 253));

		myMaxStreakDisplay.SetFont(*gFontManager.getResource("Data/Resources/arial.ttf"));
		myMaxStreakDisplay.SetPosition(366, 590);
		myMaxStreakDisplay.SetSize(15);
		myMaxStreakDisplay.SetStyle(sf::String::Bold);
		myMaxStreakDisplay.SetColor(sf::Color(132, 199, 253));

		myPointsDisplay.SetFont(*gFontManager.getResource("Data/Resources/arial.ttf"));
		myPointsDisplay.SetPosition(539, 589);
		myPointsDisplay.SetSize(18);
		myPointsDisplay.SetStyle(sf::String::Bold);
		myPointsDisplay.SetColor(sf::Color(255,243,108));

		myCountdownDisplay.SetFont(*gFontManager.getResource("Data/Resources/arial.ttf"));
		myCountdownDisplay.SetPosition(510, 638);
	}
	~GameplayView() {}
	void Update();
	void Draw(sf::RenderTarget& Target);
};
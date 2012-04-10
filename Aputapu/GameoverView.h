#pragma once

#include <SFML/Graphics.hpp>
#include "Cursor.h"
#include "Level.h"
#include <sstream>

class GameoverView
{
	/*/ References to models that view is using /*/
	Level& GameLevel;
	CustomCursor& Cursor;
	Ball& YesButton;
	Ball& NoButton;
	sf::Sprite& Background;
	sf::String myPointsDisplay;
public:
	GameoverView(Level& refLevel, CustomCursor& refCursor, sf::Sprite& refBg, Ball& refYes, Ball& refNo): GameLevel(refLevel), Cursor(refCursor), Background(refBg), YesButton(refYes), NoButton(refNo)
	{
		YesButton.SetPosition(364, 506);
		NoButton.SetPosition(632, 506);
		Background.SetPosition(296,177);
		myPointsDisplay.SetPosition(500, 340);
		myPointsDisplay.SetFont(*gFontManager.getResource("Data/Resources/arial.ttf"));
		myPointsDisplay.SetSize(30);
		std::ostringstream ss;
		ss << GameLevel.GetPoints();
		myPointsDisplay.SetText(ss.str());
	}
	~GameoverView() {}
	void Draw(sf::RenderTarget& Target);
};
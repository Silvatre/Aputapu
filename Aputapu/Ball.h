#pragma once

#include "AnimatedButton.h"
#include "ButtonManager.h"
#include "FontManager.h"

extern ButtonManager gButtonManager;
extern FontManager gFontManager;

class Ball: public sf::AnimatedButton
{
public:
	enum Color{
		Red,
		Green,
		Blue,
		Yellow,
		Violet,
		Count
	};
private:
	Color myColor;
	sf::String myActiveString;	// String displayed when ball is activated
	bool myActivated;
public:
	Ball(): myActivated(false)
	{
		myActiveString.SetFont(*gFontManager.getResource("Data/Resources/arial.ttf"));
		myActiveString.SetText("+");
		RandomColor();
	}
	Ball(Color BallColor): myColor(BallColor), myActivated(false)
	{
		myActiveString.SetFont(*gFontManager.getResource("Data/Resources/arial.ttf"));
		myActiveString.SetText("+");
		SetColor(BallColor);
	}
	virtual ~Ball();
	bool isActivated() const;
	void Activate();
	void RandomColor();
	void RandomColor(int Ammount);
	void SetColor(Color);
	Color GetColor() const;
	void Draw(sf::RenderTarget& Target);
	void Render(sf::RenderTarget& Target);
};
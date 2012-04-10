#pragma once

#include <SFML/Graphics.hpp>
#include "BallsCollection.h"

class Selection: public sf::Shape
{
	BallsCollection* myArea;
	Vector2i myFirstCoords;
	Vector2i myLastCoords;
	bool myMouseButtonPressed;
	bool mySelectionPassed;
	int myMaximumStreak;
public:
	Selection(): myArea(NULL), myFirstCoords(-1,-1), myLastCoords(-1,-1), myMouseButtonPressed(false), mySelectionPassed(false), myMaximumStreak(0)
	{
		this->Shape::operator=(sf::Shape::Rectangle(-1, -1, -1, -1, sf::Color::White, 3, sf::Color::White));
		this->EnableFill(false);
		this->EnableOutline(true);
	}

	Selection(BallsCollection* newArea): myArea(newArea), myFirstCoords(-1,-1), myLastCoords(-1,-1), myMouseButtonPressed(false), myMaximumStreak(0)
	{
		this->Shape::operator=(sf::Shape::Rectangle(-1, -1, -1, -1, sf::Color::White, 3, sf::Color::White));
		this->EnableFill(false);
		this->EnableOutline(true);
	}

	~Selection() {}
	int GetSelectedAmmount() const;
	int GetMaximumStreak() const;
	int GetUnactivatedAmmount() const;
	void SetArea(BallsCollection* newArea);
	bool Validate();
	bool isSelectionPassed();
	void MouseButtonPressedEvent(Vector2i newPosition);
	int MouseButtonReleasedEvent();	// Returns activated items
	void MouseMovedEvent(Vector2i newPosition);
	void GroupCoords(Vector2i& First, Vector2i& Last) const;
	void Draw(RenderTarget& Target);
	void Update();
};
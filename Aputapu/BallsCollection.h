#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Ball.h"

using namespace sf;

class BallsCollection
{
private:
	std::vector<std::vector<Ball>> myCollection;
	int myColors;
protected:
	virtual void Render(RenderTarget& Target);
public:
	BallsCollection() {}
	BallsCollection(int ColumnsX, int RowsY, int Colors);
	~BallsCollection();
	Vector2i MouseMovedEvent(Event::MouseMoveEvent&);
	Vector2i MouseButtonPressedEvent(Event::MouseButtonEvent&);
	int GetColors() const;
	int GetUnactivated(sf::Vector2i First, Vector2i Last) const;
	int Activate(sf::Vector2i First, Vector2i Last); // Returns number of activated balls
	void AnimatedBlink();
	void Randomize(sf::Vector2i First, Vector2i Last);
	void Randomize(sf::Vector2i First, Vector2i Last, int Colors);
	bool CollectionActivated(); // Checks if all balls in collection are activated
	void Draw(RenderTarget& Target);
	void Update();
	std::vector<Ball>& operator[](int);
};
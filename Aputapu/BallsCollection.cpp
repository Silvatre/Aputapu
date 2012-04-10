#include "BallsCollection.h"
#include <SFML/Graphics.hpp>

using namespace sf;

BallsCollection::~BallsCollection()
{}

std::vector<Ball>& BallsCollection::operator[](int Num)
{
	return myCollection[Num];
}

BallsCollection::BallsCollection(int ColumnsX, int RowsY, int Colors)
{
	myColors = Colors;
	Ball RandomBall;
	/*/ Center of screen /*/
	Vector2f ItemSize(RandomBall.GetSubRect().GetHeight()+10, RandomBall.GetSubRect().GetWidth()+2);
	ItemSize.x *= ColumnsX;
	ItemSize.y *= RowsY;
	/*/*/
	RandomBall.SetPosition( (516 - ItemSize.x/2), (299 - ItemSize.y/2));

	// Creating X columns of random balls
	std::vector<Ball> Buttons(ColumnsX, RandomBall);
	for (unsigned int i = 1; i<Buttons.size(); ++i)
	{
		Buttons[i].SetPosition( (Buttons[i-1].GetPosition().x+Buttons[i-1].GetSubRect().GetHeight()+10), Buttons[i-1].GetPosition().y);
	}
	// Creating Y rows of random balls
	std::vector<std::vector<Ball>> Buttons2D(RowsY, Buttons);
	for (unsigned int i = 0; i<Buttons2D.size(); ++i)
	{
		for (unsigned int j = 0; j<Buttons2D[i].size(); ++j)
		{
			Buttons2D[i][j].SetY(RandomBall.GetPosition().y+i*(RandomBall.GetSubRect().GetWidth()+2));
			Buttons2D[i][j].RandomColor(myColors);
		}
	}
	myCollection.assign(Buttons2D.begin(), Buttons2D.end());	
}

void BallsCollection::Render(RenderTarget& Target)
{
	for (unsigned int i = 0; i<myCollection.size(); ++i)
	{
		for (unsigned int j = 0; j<myCollection[i].size(); ++j)
		{
			myCollection[i][j].Render(Target);
		}
	}
}

void BallsCollection::AnimatedBlink()
{
	for (unsigned int i = 0; i<myCollection.size(); ++i)
	{
		for (unsigned int j = 0; j<myCollection[i].size(); ++j)
		{
			myCollection[i][j].Play();
		}
	}
}

void BallsCollection::Update()
{
	for (unsigned int i = 0; i<myCollection.size(); ++i)
	{
		for (unsigned int j = 0; j<myCollection[i].size(); ++j)
		{
			myCollection[i][j].Update();
		}
	}
}

void BallsCollection::Draw(RenderTarget& Target)
{
	for (unsigned int i = 0; i<myCollection.size(); ++i)
	{
		for (unsigned int j = 0; j<myCollection[i].size(); ++j)
		{
			myCollection[i][j].Draw(Target);
		}
	}
}

Vector2i BallsCollection::MouseMovedEvent(Event::MouseMoveEvent& Event)
{
	Vector2i Coordinates(-1,-1);
	for (unsigned int i = 0; i<myCollection.size(); ++i)
	{
		for (unsigned int j = 0; j<myCollection[i].size(); ++j)
		{
			if (myCollection[i][j].MouseMovedOn(Event))
			{
				Coordinates.x = i;
				Coordinates.y = j;
			}
			else
			if (myCollection[i][j].MouseMovedOut(Event))
			{
				Coordinates.x = i;
				Coordinates.y = j;
			}
		}
	}
	return Coordinates;
}

int BallsCollection::Activate(sf::Vector2i First, Vector2i Last)
{
	int ActivatedBalls = 0;
	for (unsigned int i = First.x; i <= Last.x; ++i)
	{
		for (unsigned int j = First.y; j <= Last.y; ++j)
		{
			if (!myCollection[i][j].isActivated())
			{
				ActivatedBalls++;
				myCollection[i][j].Activate();
			}
		}
	}
	return ActivatedBalls;
}

int BallsCollection::GetUnactivated(sf::Vector2i First, Vector2i Last) const
{
	int UnactivatedBalls = 0;
	for (unsigned int i = First.x; i <= Last.x; ++i)
	{
		for (unsigned int j = First.y; j <= Last.y; ++j)
		{
			if (!myCollection[i][j].isActivated())
				UnactivatedBalls++;
		}
	}
	return UnactivatedBalls;
}

void BallsCollection::Randomize(sf::Vector2i First, Vector2i Last)
{
	Randomize(First, Last, myColors);
}

void BallsCollection::Randomize(sf::Vector2i First, Vector2i Last, int Colors)
{
	for (unsigned int i = First.x; i <= Last.x; ++i)
	{
		for (unsigned int j = First.y; j <= Last.y; ++j)
		{
			myCollection[i][j].RandomColor(Colors);
		}
	}
}

int BallsCollection::GetColors() const
{
	return myColors;
}

bool BallsCollection::CollectionActivated()
{
	for (unsigned int i = 0; i<myCollection.size(); ++i)
	{
		for (unsigned int j = 0; j<myCollection[i].size(); ++j)
		{
			if (!myCollection[i][j].isActivated())
			return false;
		}
	}
	return true;
}

Vector2i BallsCollection::MouseButtonPressedEvent(Event::MouseButtonEvent& Event)
{
	Vector2i Coordinates(-1,-1);
	for (unsigned int i = 0; i<myCollection.size(); ++i)
	{
		for (unsigned int j = 0; j<myCollection[i].size(); ++j)
		{
			if (myCollection[i][j].ButtonPressed(Event))
			{
				Coordinates.x = i;
				Coordinates.y = j;
			}
		}
	}
	return Coordinates;
}
#include "Selection.h"

int Selection::MouseButtonReleasedEvent()
{
	int Activated = 0;
	if (mySelectionPassed)
	{
		GroupCoords(myFirstCoords, myLastCoords);
		Activated = myArea->Activate(myFirstCoords, myLastCoords);
		myArea->Randomize(myFirstCoords, myLastCoords);
		// Update max streak, only unactivated balls counts
		if (Activated > myMaximumStreak)
			myMaximumStreak = Activated;
		mySelectionPassed = false;
	}
	myMouseButtonPressed = false;
	return Activated;
}

void Selection::MouseMovedEvent(Vector2i newPosition)
{
	if (myMouseButtonPressed == true)
	{
		MouseButtonPressedEvent(newPosition);
		Validate();
	}
}

void Selection::MouseButtonPressedEvent(Vector2i newPosition)
{
	if( newPosition.x >= 0)
	{
		if (myMouseButtonPressed == false)
		{
			myMouseButtonPressed = true;
			myFirstCoords = newPosition;
		}
		myLastCoords = newPosition;
	}
}

bool Selection::isSelectionPassed()
{
	return mySelectionPassed;
}

void Selection::SetArea(BallsCollection* newArea)
{
	myArea = newArea;
}

void Selection::Update()
{
	if (myMouseButtonPressed)
	{
		if (myFirstCoords == myLastCoords)
		{
			sf::IntRect Position = (*myArea)[myFirstCoords.x][myFirstCoords.y].GetSubRect();
			Position.Offset((*myArea)[myFirstCoords.x][myFirstCoords.y].GetPosition().x, (*myArea)[myFirstCoords.x][myFirstCoords.y].GetPosition().y);
			
			this->SetPointPosition(0, sf::Vector2f(Position.Left, Position.Top));
			this->SetPointPosition(1, sf::Vector2f(Position.Right, Position.Top));
			this->SetPointPosition(2, sf::Vector2f(Position.Right, Position.Bottom));
			this->SetPointPosition(3, sf::Vector2f(Position.Left, Position.Bottom));
		}
		else
		{
			sf::IntRect Position1 = (*myArea)[myFirstCoords.x][myFirstCoords.y].GetSubRect();
			Position1.Offset((*myArea)[myFirstCoords.x][myFirstCoords.y].GetPosition().x, (*myArea)[myFirstCoords.x][myFirstCoords.y].GetPosition().y);

			sf::IntRect Position2 = (*myArea)[myLastCoords.x][myLastCoords.y].GetSubRect();
			Position2.Offset((*myArea)[myLastCoords.x][myLastCoords.y].GetPosition().x, (*myArea)[myLastCoords.x][myLastCoords.y].GetPosition().y);

			if ((Position1.Left < Position2.Left) && (Position1.Bottom > Position2.Bottom))
			{
				Position1.Top = Position1.Bottom;
				Position2.Bottom = Position2.Top;

			}
			else 
			{
				if ((Position1.Left > Position2.Left) && (Position1.Top < Position2.Top))
				{
					Position2.Top = Position2.Bottom;
					Position1.Bottom = Position1.Top;
				}

				if ((Position1.Left > Position2.Left) || (Position1.Top > Position2.Bottom))
				{
					sf::IntRect Temp;
					Temp = Position1;
					Position1 = Position2;
					Position2 = Temp;
				}
			}
			this->SetPointPosition(0, sf::Vector2f(Position1.Left, Position1.Top));
			this->SetPointPosition(1, sf::Vector2f(Position2.Right, Position1.Top));
			this->SetPointPosition(2, sf::Vector2f(Position2.Right, Position2.Bottom));
			this->SetPointPosition(3, sf::Vector2f(Position1.Left, Position2.Bottom));
		}
	}
}

int Selection::GetSelectedAmmount() const
{
	int Columns = 0;
	int Rows = 0;
	if (myMouseButtonPressed)
	{
		myFirstCoords.x > myLastCoords.x ? Columns = myFirstCoords.x - myLastCoords.x + 1 : Columns = myLastCoords.x - myFirstCoords.x +1;
		myFirstCoords.y > myLastCoords.y ? Rows = myFirstCoords.y - myLastCoords.y + 1 : Rows = myLastCoords.y - myFirstCoords.y +1;
	}
	return Columns*Rows;
}

int Selection::GetUnactivatedAmmount() const
{
	int Ammount = 0;
	if (myMouseButtonPressed)
	{
		Vector2i TempFirst = myFirstCoords;
		Vector2i TempLast = myLastCoords;
		GroupCoords(TempFirst, TempLast);
		Ammount = myArea->GetUnactivated(TempFirst, TempLast);
	}
	return Ammount;
}

void Selection::GroupCoords(Vector2i& First, Vector2i& Last) const
{
	if (First.y > Last.y)
	{
		int Temp = First.y;
		First.y = Last.y;
		Last.y = Temp;
	}
	if (First.x > Last.x)
	{
		int Temp = First.x;
		First.x = Last.x;
		Last.x = Temp;
	}
}

int Selection::GetMaximumStreak() const
{
	return myMaximumStreak;
}

bool Selection::Validate()
{
	if ( (myLastCoords.x != myFirstCoords.x) && (myLastCoords.y != myFirstCoords.y) )
	{
		Ball::Color Color = (*myArea)[myLastCoords.x][myLastCoords.y].GetColor();
		if ( ((*myArea)[myLastCoords.x][myLastCoords.y].GetColor() == Color) &&  ((*myArea)[myFirstCoords.x][myFirstCoords.y].GetColor() == Color) && ((*myArea)[myFirstCoords.x][myLastCoords.y].GetColor() == Color) && ((*myArea)[myLastCoords.x][myFirstCoords.y].GetColor() == Color) )
		{
			mySelectionPassed = true;
			(*myArea)[myLastCoords.x][myLastCoords.y].Play();
			(*myArea)[myFirstCoords.x][myFirstCoords.y].Play();
			(*myArea)[myFirstCoords.x][myLastCoords.y].Play();
			(*myArea)[myLastCoords.x][myFirstCoords.y].Play();
			return true;
		}
		else
		{
			mySelectionPassed = false;
			return false;
		}
	}
	return false;
}

void Selection::Draw(RenderTarget& Target)
{
	if (myMouseButtonPressed)
		Target.Draw(*this);
}
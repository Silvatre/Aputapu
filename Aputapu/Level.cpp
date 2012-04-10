#include "Level.h"
#include <math.h>

Level::Level()
{
	GenerateMaps(5);
	myCurrentMap = &myGeneratedMaps[0];
	mySelection.SetArea(myCurrentMap);
	myCurrentLevel = 1;
	myLevelsFinished = false;
	myPoints = 0;
}

void Level::Restart()
{
	GenerateMaps(5);
	myCurrentMap = &myGeneratedMaps[0];
	Selection newSelection;
	mySelection = newSelection;
	mySelection.SetArea(myCurrentMap);
	myCurrentLevel = 1;
	myLevelsFinished = false;
	myPoints = 0;
}


void Level::NextLevel()
{
	if (myCurrentLevel < myGeneratedMaps.size())
	{
		myCurrentMap = &myGeneratedMaps[myCurrentLevel++];
		mySelection.SetArea(myCurrentMap);
	}
	else
		myLevelsFinished = true;
	myCurrentMap->AnimatedBlink();
}

bool Level::LevelCompleted()
{
	if (myCurrentMap->CollectionActivated())
	{
		return true;
	}
	else
		return false;
}

bool Level::LevelsCompleted() const
{
	return myLevelsFinished;
}


void Level::MouseMovedEvent(Event::MouseMoveEvent Event)
{
	mySelection.MouseMovedEvent(myCurrentMap->MouseMovedEvent(Event));
}

void Level::MouseButtonPressedEvent(Event::MouseButtonEvent Event)
{
	mySelection.MouseButtonPressedEvent(myCurrentMap->MouseButtonPressedEvent(Event));	
}

void Level::MouseButtonReleasedEvent(Event::MouseButtonEvent)
{
	AddPoints(CalculatePoints(mySelection.MouseButtonReleasedEvent()));
}

int Level::CalculatePoints(int ActivatedItems)
{
	return ActivatedItems*ActivatedItems;
}

void Level::AddPoints(int Ammount)
{
	myPoints += Ammount;
}

unsigned int Level::GetPoints() const
{
	return myPoints;
}

int Level::GetSelectedItems() const
{
	return mySelection.GetSelectedAmmount();
}

int Level::GetUnactivatedItems()
{
	return mySelection.GetUnactivatedAmmount();
}

int Level::GetCurrentLevel() const
{
	return myCurrentLevel;
}

int Level::GetMaximumStreak() const
{
	return mySelection.GetMaximumStreak();
}


void Level::Update()
{
	myCurrentMap->Update();
	mySelection.Update();
}

void Level::Draw(RenderTarget& Target)
{
	myCurrentMap->Draw(Target);
	mySelection.Draw(Target);
}

void Level::GenerateMaps(unsigned int Ammount)
{
	BallsCollection Level1(7,8,2), Level2(9,8,3), Level3(11,8, 4), Level4(13,8,5);
	myGeneratedMaps.clear();
	myGeneratedMaps.push_back(Level1);
	myGeneratedMaps.push_back(Level2);
	myGeneratedMaps.push_back(Level3);
	myGeneratedMaps.push_back(Level4);
}
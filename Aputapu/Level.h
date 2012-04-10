#pragma once

#include "Button.h"
#include "BallsCollection.h"
#include "Selection.h"
#include <vector>

class Level
{
	BallsCollection* myCurrentMap;
	Selection mySelection;
	std::vector<BallsCollection> myGeneratedMaps;
	int myCurrentLevel;	// Starting from 0 (Level 1)
	unsigned int myPoints;
	bool myLevelsFinished;
public:
	
	Level();
	~Level() {}
	int GetUnactivatedItems();
	int GetSelectedItems() const;
	int GetMaximumStreak() const;
	int GetCurrentLevel() const;
	bool LevelsCompleted() const;
	unsigned int GetPoints() const;
	void AddPoints(int Value);
	int CalculatePoints(int ActivatedItems);
	void Update();
	void Draw(RenderTarget& Target);
	void GenerateMaps(unsigned int Ammount);
	void NextLevel();
	bool LevelCompleted(); // Conditions of completing level: All balls in the current map has been activated
	void Restart();
	void MouseMovedEvent(Event::MouseMoveEvent);
	void MouseButtonPressedEvent(Event::MouseButtonEvent);
	void MouseButtonReleasedEvent(Event::MouseButtonEvent);
};


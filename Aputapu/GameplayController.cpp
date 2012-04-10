#include "GameplayController.h"
#include "GameoverController.h"
#include "GameplayConfiguration.h"
#include "Cursor.h"
#include "Selection.h"
#include "Level.h"
#include <vector>
#include <stdlib.h>

GameplayController::GameplayController(sf::RenderWindow* toAdd)
{
	App = toAdd;
	myPlaying = true;
	myCountdown.SetCount(180);
	Background.SetImage(*gImageManager.getResource("Data/Resources/Background.jpg"));
	Cursor = CustomCursor(*gImageManager.getResource("Data/Resources/Cursor.png"), App);
	View = new GameplayView(GameLevel, Cursor, Background, myCountdown);
}

void GameplayController::RestartGame()
{
	myPlaying = true;
	myCountdown.SetCount(180);
	myCountdown.Start();
	GameLevel.Restart();
}

void GameplayController::EndGame()
{
	myPlaying = false;
}

void GameplayController::StartGame()
{		
	while (App->IsOpened() && myPlaying)
	{
		sf::Event Event;
		while (App->GetEvent(Event))
		{
			switch(Event.Type)
			{
				case sf::Event::Closed:
					App->Close();
					break;
				case sf::Event::MouseMoved:
					GameLevel.MouseMovedEvent(Event.MouseMove);
					break;
				case sf::Event::MouseButtonPressed:
					GameLevel.MouseButtonPressedEvent(Event.MouseButton);
					break;
				case sf::Event::MouseButtonReleased:
					GameLevel.MouseButtonReleasedEvent(Event.MouseButton);
					break;
				default:
					break;
			}
		}

		if (GameLevel.LevelCompleted())
		{
			GameLevel.AddPoints(GameLevel.GetCurrentLevel() * 500);
			GameLevel.NextLevel();	
		}

		if (GameLevel.LevelsCompleted() || (myCountdown.isFinished()))
			if (GameoverController(App, GameLevel, Cursor).PlayAgain())
				RestartGame();
			else
				EndGame();

		App->Clear(); 
		View->Draw(*App);
		App->Display();
	}
}
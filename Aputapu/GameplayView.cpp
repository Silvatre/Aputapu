#include "GameplayView.h"
#include <sstream>

void GameplayView::Draw(sf::RenderTarget& Target)
{
	Update();
	GameLevel.Update();
	Cursor.Update();

	Target.Draw(Background);
	GameLevel.Draw(Target);
	Target.Draw(mySelectedBallsDisplay);
	Target.Draw(myLevelDisplay);
	Target.Draw(myMaxStreakDisplay);
	Target.Draw(myPointsDisplay);
	Target.Draw(myCountdownDisplay);
	Target.Draw(Cursor);
}

void GameplayView::Update()
{
	// Selected Balls
	std::ostringstream ss;
	ss << GameLevel.GetSelectedItems();
	ss << '(';
	ss << GameLevel.GetUnactivatedItems();
	ss << ')';
	mySelectedBallsDisplay.SetText(ss.str());
	ss.str("");

	// Level
	ss << GameLevel.GetCurrentLevel();
	myLevelDisplay.SetText(ss.str());
	ss.str("");

	// Max streak
	int Streak = GameLevel.GetMaximumStreak();
	ss << Streak;
	myMaxStreakDisplay.SetText(ss.str());
	Streak < 10 ? myMaxStreakDisplay.SetPosition(691, 590) : myMaxStreakDisplay.SetPosition(687, 590);
	ss.str("");

	// Points
	ss << GameLevel.GetPoints();
	myPointsDisplay.SetText(ss.str());
	ss.str("");

	// Countdown
	ss << myCountdown.GetCurrentCount();
	myCountdownDisplay.SetText(ss.str());

	// Changing color
	if(myCountdown.GetCurrentCount() > 60)
		myCountdownDisplay.SetColor(sf::Color::White);
	else if(myCountdown.GetCurrentCount() <= 30)
		myCountdownDisplay.SetColor(sf::Color::Red);
	else
		myCountdownDisplay.SetColor(sf::Color::Yellow);

	if(myCountdown.GetCurrentCount() < 10)
		myCountdownDisplay.SetPosition(524, 638);
	else if(myCountdown.GetCurrentCount() < 100)
		myCountdownDisplay.SetPosition(517, 638);
	else myCountdownDisplay.SetPosition(510, 638);
}

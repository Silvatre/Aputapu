#include "GameoverView.h"

void GameoverView::Draw(sf::RenderTarget& Target)
{
	YesButton.Update();
	NoButton.Update();
	GameLevel.Update();
	Cursor.Update();
	
	Target.Draw(Background);
	YesButton.Draw(Target);
	NoButton.Draw(Target);
	Target.Draw(myPointsDisplay);
	Target.Draw(Cursor);
}
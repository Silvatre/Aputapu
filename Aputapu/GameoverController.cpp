#include "GameoverController.h"
#include "Cursor.h"
#include "Level.h"

bool GameoverController::PlayAgain()
{		
	while (App->IsOpened())
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
					YesButton.MouseMovedOn(Event.MouseMove);
					YesButton.MouseMovedOut(Event.MouseMove);
					NoButton.MouseMovedOn(Event.MouseMove);
					NoButton.MouseMovedOut(Event.MouseMove);
					break;
				case sf::Event::MouseButtonPressed:
					if(YesButton.ButtonPressed(Event.MouseButton))
						return true;
					else if (NoButton.ButtonPressed(Event.MouseButton))
						return false;
					break;
				case sf::Event::MouseButtonReleased:
					YesButton.ButtonReleased(Event.MouseButton);
					NoButton.ButtonReleased(Event.MouseButton);
					break;
				default:
					break;
			}
		}

		App->Clear(); 
		View->Draw(*App);
		App->Display();
	}
	return false;
}
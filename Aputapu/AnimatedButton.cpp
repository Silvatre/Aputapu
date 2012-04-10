#include "AnimatedButton.h"

using namespace sf;

AnimatedButton::AnimatedButton()
{
	my_GotReversedMouseMoveAnimation = true;
	my_State = isIdle;
	my_GotIdleResource = false;
	my_GotMouseButtonPressedResource = false;
	my_GotMouseButtonReleasedResource = false;
	my_GotMouseMovedOnResource = false; 
	my_GotMouseMovedOutResource = false;
}

AnimatedButton& AnimatedButton::operator=(const Animation& toCpy)
{
	this->Animation::operator=(toCpy);
	return *this;
}

bool AnimatedButton::ButtonPressed(Event::MouseButtonEvent Event)
{
	sf::IntRect Position = this->GetSubRect();
	Position.Offset(this->GetPosition().x, this->GetPosition().y);

	
	if (Event.Button == Mouse::Left)
		if (Position.Contains(Event.X, Event.Y))
		{
			if (my_GotMouseButtonPressedResource)
			{
				*this = my_MouseButtonPressedResource;
				Play();
			}
			return true;
		}
	return false;
}

bool AnimatedButton::ButtonReleased(Event::MouseButtonEvent Event)
{
	sf::IntRect Position = this->GetSubRect();
	Position.Offset(this->GetPosition().x, this->GetPosition().y);

	
	if (Event.Button == Mouse::Left)
		if (Position.Contains(Event.X, Event.Y))
		{
			if (my_GotMouseButtonReleasedResource)
			{
				*this = my_MouseButtonReleasedResource;
				Play();
			}
			return true;
		}
	return false;
}

bool AnimatedButton::MouseMovedOn(Event::MouseMoveEvent Event)
{
	sf::IntRect Position = this->GetSubRect();
	Position.Offset(this->GetPosition().x, this->GetPosition().y);

	
	if (Position.Contains(Event.X, Event.Y))
	{
		if (my_State != isMouseMovedOn)
		if (my_GotMouseMovedOnResource)
		{
			my_State = isMouseMovedOn;
			*this = my_MouseMovedOnResource;
			Play();
		}
		return true;
	}
	return false;
}


bool AnimatedButton::MouseMovedOut(Event::MouseMoveEvent Event)
{
	sf::IntRect Position = this->GetSubRect();
	Position.Offset(this->GetPosition().x, this->GetPosition().y);
	
	if (!(Position.Contains(Event.X, Event.Y)))
	if (my_State == isMouseMovedOn)
	{
		if (my_GotReversedMouseMoveAnimation)
		{
			if (my_GotMouseMovedOnResource)
			{	
				Reverse();
				if (!isPlaying)
				{
					Reset();
					Play();
				}
			}
		}
		else 
		if (my_GotMouseMovedOutResource)
		{
			*this = my_MouseMovedOutResource;
			Play();
		}
		my_State = isMouseMovedOut;
		return true;
	}
	return false;
}

void AnimatedButton::Reset()
{
	if (my_State == isMouseMovedOut)
	{
		my_State = isIdle;
		if (my_GotIdleResource)
		{
			SetReverse(false);
			*this = my_IdleResource;
		}
	}
	// Stop at last frame when mouse moved on animation is over
	else if (my_State == isMouseMovedOn)
		Reverse();
	Animation::Reset();
}

AnimatedButton& AnimatedButton::operator=(const AnimatedButton& toCpy)
{
	my_IdleResource = toCpy.my_IdleResource;
	my_MouseButtonPressedResource = toCpy.my_MouseButtonPressedResource;
	my_MouseButtonReleasedResource = toCpy.my_MouseButtonReleasedResource;
	my_MouseMovedOnResource = toCpy.my_MouseMovedOnResource;
	my_MouseMovedOutResource = toCpy.my_MouseMovedOutResource;
	my_GotIdleResource = toCpy.my_GotIdleResource;
	my_GotMouseButtonPressedResource = toCpy.my_GotMouseButtonPressedResource;
	my_GotMouseButtonReleasedResource = toCpy.my_GotMouseButtonReleasedResource;
	my_GotMouseMovedOnResource = toCpy.my_GotMouseMovedOnResource;
	my_GotMouseMovedOutResource = toCpy.my_GotMouseMovedOutResource;
	my_GotReversedMouseMoveAnimation = toCpy.my_GotReversedMouseMoveAnimation;
	*this = my_IdleResource;
	return *this;
}
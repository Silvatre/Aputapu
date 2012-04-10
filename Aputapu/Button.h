#pragma once
#include <SFML/Graphics.hpp>

namespace sf{

template <typename T>
class Button
{
protected:
	enum State
	{
		isIdle,
		isButtonPressed,
		isButtonReleased,
		isMouseMovedOn,
		isMouseMovedOut
	};
	T my_IdleResource;
	T my_MouseButtonPressedResource;
	T my_MouseButtonReleasedResource;
	T my_MouseMovedOnResource;
	T my_MouseMovedOutResource;
	bool my_GotIdleResource;
	bool my_GotMouseButtonPressedResource;
	bool my_GotMouseButtonReleasedResource;
	bool my_GotMouseMovedOnResource;
	bool my_GotMouseMovedOutResource;
	State my_State;

public:
	Button() {}
	virtual ~Button() {}
	/*/ Setting up states /*/
	void SetIdleState(const T& newState)
	{
	my_IdleResource = newState;
	my_GotIdleResource = true;
	}
	void SetMouseButtonPressedState(const T& newState)
	{
	my_MouseButtonPressedResource = newState;
	my_GotMouseMovedOnResource = true;
	}
	void SetMouseButtonReleasedState(const T& newState)
	{
	my_MouseButtonReleasedResource = newState;
	my_GotMouseButtonReleasedResource = true;
	}
	void SetMouseMovedOnState(const T& newState)
	{
	my_MouseMovedOnResource = newState;
	my_GotMouseMovedOnResource = true;
	}
	void SetMouseMovedOutState(const T& newState)
	{
	my_MouseMovedOutResource = newState;
	my_GotMouseMovedOutResource = true;
	}
	/*/ Handling mouse events /*/
	virtual bool ButtonPressed(Event::MouseButtonEvent) = 0;
	virtual bool ButtonReleased(Event::MouseButtonEvent) = 0;
	virtual bool MouseMovedOn(Event::MouseMoveEvent) = 0;
	virtual bool MouseMovedOut(Event::MouseMoveEvent) = 0;
};
} // Namespace sf
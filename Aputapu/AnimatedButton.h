#pragma once

#include "Button.h"
#include "Animation.h"

namespace sf {

class AnimatedButton: public Button<Animation>, public Animation
{
	bool my_GotReversedMouseMoveAnimation; // MouseOut = Reversed MouseOn
public:
	AnimatedButton();
	virtual ~AnimatedButton() {}
	virtual void Reset();
	/*/ Handling mouse events /*/
	virtual bool ButtonPressed(Event::MouseButtonEvent);
	virtual bool ButtonReleased(Event::MouseButtonEvent);
	virtual bool MouseMovedOn(Event::MouseMoveEvent);
	virtual bool MouseMovedOut(Event::MouseMoveEvent);
	/*/ Operators /*/
	AnimatedButton& operator=(const Animation& toCpy);
	AnimatedButton& operator=(const AnimatedButton& toCpy);
};

}	// Namespace sf
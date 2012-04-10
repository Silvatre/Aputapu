#pragma once

#include "ButtonManager.h"
#include "Configuration.h"

class BallsConfiguration: public Configuration <ButtonManager>
{
public:
	BallsConfiguration() {}
	BallsConfiguration(ButtonManager* toLink);
	void Init();
};
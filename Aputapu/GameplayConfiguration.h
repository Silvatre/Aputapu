#pragma once

#include "BallsConfiguration.h"
#include "GameplayImages.h"
#include "ImageManager.h"
#include "ButtonManager.h"
#include "Configuration.h"
#include <stdlib.h>
#include <time.h>

class GameplayConfiguration
{
	ButtonManager* myButtonManager;
	ImageManager* myImageManager;
	BallsConfiguration myGameplayBalls;
	GameplayImages myGameplayImages;
public:
	GameplayConfiguration() {}
	GameplayConfiguration(ButtonManager* Buttons, ImageManager* Images): myButtonManager(Buttons), myImageManager(Images), myGameplayBalls(myButtonManager), myGameplayImages(myImageManager) 
	{
		srand((unsigned int)time( NULL ));
	}
	~GameplayConfiguration()
	{
		myGameplayBalls.Release();
		myGameplayImages.Release();
	}
};
#pragma once

#include "ImageManager.h"
#include "Configuration.h"

class GameplayImages: public Configuration <ImageManager>
{
public:
	GameplayImages() {}
	GameplayImages(ImageManager* toLink);
	void Init();
};
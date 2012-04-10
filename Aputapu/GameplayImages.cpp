#include "GameplayImages.h"
#include "AnimationManager.h"

GameplayImages::GameplayImages(ImageManager* toLink)
{
	myResource = toLink;
	Init();
}

void GameplayImages::Init()
{
	myResource->getResource("Data/Resources/Background.jpg");
	myResource->getResource("Data/Resources/Gameover.png");
	myResource->getResource("Data/Resources/Cursor.png");
	myAdded.push_back("Data/Resources/Background.jpg");
	myAdded.push_back("Data/Resources/Gameover.png");
	myAdded.push_back("Data/Resources/Cursor.png");
}
#include "BallsConfiguration.h"
#include "AnimationManager.h"

BallsConfiguration::BallsConfiguration(ButtonManager* toLink)
{
	myResource = toLink;
	Init();
}

void BallsConfiguration::Init()
{
	AnimationManager LocalAnimationManager;

	// BlueBall
	LocalAnimationManager.AddResource("Data/Balls/Blue/MouseOn/", "mouseon", ".png", 14, "Blue.MouseOn");
	sf::Animation MouseOn = LocalAnimationManager.getResource("Blue.MouseOn");

	MouseOn.SetLoop(false);
	MouseOn.SetFPS(35);

	sf::AnimatedButton Ball;
	Ball.SetIdleState(MouseOn);
	Ball.SetMouseMovedOnState(MouseOn);

	myResource->AddResource(Ball, "BlueBall");

	myAdded.push_back("BlueBall");
	
	// RedBall
	MouseOn = LocalAnimationManager.AddResource("Data/Balls/Red/MouseOn/", "mouseon", ".png", 14, "Red.MouseOn");
	MouseOn.SetLoop(false);
	MouseOn.SetFPS(35);

	Ball.SetIdleState(MouseOn);
	Ball.SetMouseMovedOnState(MouseOn);

	myResource->AddResource(Ball, "RedBall");
	myAdded.push_back("RedBall");

	// VioletBall
	MouseOn = LocalAnimationManager.AddResource("Data/Balls/Violet/MouseOn/", "mouseon", ".png", 14, "Violet.MouseOn");
	MouseOn.SetLoop(false);
	MouseOn.SetFPS(35);

	Ball.SetIdleState(MouseOn);
	Ball.SetMouseMovedOnState(MouseOn);

	myResource->AddResource(Ball, "VioletBall");
	myAdded.push_back("VioletBall");

	// GreenBall
	MouseOn = LocalAnimationManager.AddResource("Data/Balls/Green/MouseOn/", "mouseon", ".png", 14, "Green.MouseOn");
	MouseOn.SetLoop(false);
	MouseOn.SetFPS(35);

	Ball.SetIdleState(MouseOn);
	Ball.SetMouseMovedOnState(MouseOn);

	myResource->AddResource(Ball, "GreenBall");
	myAdded.push_back("GreenBall");
	
	// YellowBall
	MouseOn = LocalAnimationManager.AddResource("Data/Balls/Yellow/MouseOn/", "mouseon", ".png", 14, "Yellow.MouseOn");
	MouseOn.SetLoop(false);
	MouseOn.SetFPS(35);

	Ball.SetIdleState(MouseOn);
	Ball.SetMouseMovedOnState(MouseOn);

	myResource->AddResource(Ball, "YellowBall");
	myAdded.push_back("YellowBall");
}
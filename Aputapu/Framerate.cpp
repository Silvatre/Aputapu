#include "Framerate.h"

using namespace sf;
FramesPerSecond::FramesPerSecond()
{
	RefreshRate = 1;
	LastRefresh = 1;
	Framerate = new char[10];
	SetPosition(20,15);
}

FramesPerSecond::~FramesPerSecond()
{
	delete [] Framerate;
}

void FramesPerSecond::Update()
{
	double ElapsedTime = Clock.GetElapsedTime();
	Clock.Reset();
	if (LastRefresh >= RefreshRate)
	{
		int FramerateValue = (int) (1.f / ElapsedTime);
		SetText(itoa(FramerateValue, Framerate, 10));
		LastRefresh = 0;
	}
	else
		LastRefresh += ElapsedTime;
}


void FramesPerSecond::Draw(sf::RenderTarget& Target)
{
	Target.Draw(*this);
}
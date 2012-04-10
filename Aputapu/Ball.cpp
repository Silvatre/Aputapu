#include "Ball.h"
#include <stdlib.h>
#include <time.h>

Ball::~Ball()
{}

bool Ball::isActivated() const
{
	return myActivated;
}

Ball::Color Ball::GetColor() const
{
	return myColor;
}

void Ball::Activate()
{
	myActivated = true;
}

void Ball::RandomColor()
{
	RandomColor((int)Ball::Count);
}

void Ball::RandomColor(int Ammount)
{
	if (Ammount >= (int)Ball::Count)
		Ammount = (int)Ball::Count;
	this->SetColor( (Color) (rand() % (Ammount) ) );
}

void Ball::SetColor(Color BallColor)
{
	myColor = BallColor;

	switch(BallColor)
	{
		case Red:
			this->AnimatedButton::operator=(gButtonManager.getResource("RedBall"));
			break;

		case Green:
			this->AnimatedButton::operator=(gButtonManager.getResource("GreenBall"));
			break;

		case Blue:
			this->AnimatedButton::operator=(gButtonManager.getResource("BlueBall"));
			break;
			
		case Yellow:
			this->AnimatedButton::operator=(gButtonManager.getResource("YellowBall"));
			break;

		case Violet:
			this->AnimatedButton::operator=(gButtonManager.getResource("VioletBall"));
			break;

		default:
			break;	
	}
}

void Ball::Draw(sf::RenderTarget& Target)
{
	sf::Animation::Draw(Target);
	if (myActivated)
	{
		myActiveString.SetPosition( this->GetPosition().x + 25, this->GetPosition().y + 13 );
		Target.Draw(myActiveString);
	}
}


void Ball::Render(sf::RenderTarget& Target)
{
	sf::Animation::Draw(Target);
}
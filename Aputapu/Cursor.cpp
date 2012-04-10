#include "Cursor.h"

CustomCursor::CustomCursor()
{
	myWindow = NULL;
}

CustomCursor::~CustomCursor()
{}

void CustomCursor::Update()
{
	sf::Vector2f MousePos = myWindow->ConvertCoords(myWindow->GetInput().GetMouseX(), myWindow->GetInput().GetMouseY());
	this->SetPosition(MousePos);
}

void CustomCursor::Draw(sf::RenderTarget& Target) const
{
	Target.Draw(*this);
}
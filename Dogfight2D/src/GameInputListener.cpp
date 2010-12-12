#include "GameInputListener.h"


df::GameInputListener::GameInputListener(void)
{
}


df::GameInputListener::~GameInputListener(void)
{
}


void df::GameInputListener::ProcessEvent(sf::Event inputEvent, sf::RenderWindow &renderWindow)
{
	_navigateLeftIsPressed = renderWindow.GetInput().IsKeyDown(sf::Key::Numpad4);
	_navigateRightIsPressed = renderWindow.GetInput().IsKeyDown(sf::Key::Numpad6);
	_navigateUpIsPressed = renderWindow.GetInput().IsKeyDown(sf::Key::Numpad8);
	_navigateDownIsPressed = renderWindow.GetInput().IsKeyDown(sf::Key::Numpad2);
}
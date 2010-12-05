#include "GameInputListener.h"


df::GameInputListener::GameInputListener(void)
{
}


df::GameInputListener::~GameInputListener(void)
{
}


void df::GameInputListener::ProcessEvent(sf::Event inputEvent, sf::RenderWindow &renderWindow)
{
	_navigateLeftIsPressed = renderWindow.GetInput().IsKeyDown(sf::Key::Left);
	_navigateRightIsPressed = renderWindow.GetInput().IsKeyDown(sf::Key::Right);
	_navigateUpIsPressed = renderWindow.GetInput().IsKeyDown(sf::Key::Up);
	_navigateDownIsPressed = renderWindow.GetInput().IsKeyDown(sf::Key::Down);
}
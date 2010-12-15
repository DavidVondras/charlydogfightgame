#include "GameInputListener.h"
#include <iostream>


df::GameInputListener::GameInputListener(void)
{
	_engineInputValue = 0;
}


df::GameInputListener::~GameInputListener(void)
{
}

void df::GameInputListener::OnListenCalled(sf::RenderWindow &renderWindow)
{
	_navigateLeftIsPressed = renderWindow.GetInput().IsKeyDown(sf::Key::Numpad4);
	_navigateRightIsPressed = renderWindow.GetInput().IsKeyDown(sf::Key::Numpad6);
	_navigateUpIsPressed = renderWindow.GetInput().IsKeyDown(sf::Key::Numpad8);
	_navigateDownIsPressed = renderWindow.GetInput().IsKeyDown(sf::Key::Numpad2);

	_torqueLeftIsPressed = renderWindow.GetInput().IsKeyDown(sf::Key::Left);
	_torqueRightIsPressed = renderWindow.GetInput().IsKeyDown(sf::Key::Right);

	_engineValueChanged = false;
}


void df::GameInputListener::ProcessEvent(sf::Event inputEvent, sf::RenderWindow &renderWindow)
{
	if((inputEvent.Type == sf::Event::KeyReleased))
	{
		switch(inputEvent.Key.Code)
		{
		case sf::Key::Num0:
			_engineInputValue = 1.f;
			_engineValueChanged = true;
			break;
		case sf::Key::Num1:
			_engineInputValue = 0.1f;
			_engineValueChanged = true;
			break;
		case sf::Key::Num2:
			_engineInputValue = 0.2f;
			_engineValueChanged = true;
			break;
		case sf::Key::Num3:
			_engineInputValue = 0.3f;
			_engineValueChanged = true;
			break;
		case sf::Key::Num4:
			_engineInputValue = 0.4f;
			_engineValueChanged = true;
			break;
		case sf::Key::Num5:
			_engineInputValue = 0.5f;
			_engineValueChanged = true;
			break;
		case sf::Key::Num6:
			_engineInputValue = 0.6f;
			_engineValueChanged = true;
			break;
		case sf::Key::Num7:
			_engineInputValue = 0.7f;
			_engineValueChanged = true;
			break;
		case sf::Key::Num8:
			_engineInputValue = 0.8f;
			_engineValueChanged = true;
			break;
		case sf::Key::Num9:
			_engineInputValue = 0.9f;
			_engineValueChanged = true;
			break;
		}
	}
}
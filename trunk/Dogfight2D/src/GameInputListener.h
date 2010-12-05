#pragma once
#include "InputListener.h"

namespace df
{
	class GameInputListener: public df::InputListener
	{
	private:
		bool _navigateRightIsPressed;
		bool _navigateLeftIsPressed;
		bool _navigateUpIsPressed;
		bool _navigateDownIsPressed;

	protected:
		void ProcessEvent(sf::Event inputEvent, sf::RenderWindow &renderWindow);

	public:
		GameInputListener(void);
		~GameInputListener(void);

		bool getNavigateRightIsPressed() { return _navigateRightIsPressed; }
		bool getNavigateLeftIsPressed() { return _navigateLeftIsPressed; }
		bool getNavigateUpIsPressed() { return _navigateUpIsPressed; }
		bool getNavigateDownIsPressed() { return _navigateDownIsPressed; }
	};
}


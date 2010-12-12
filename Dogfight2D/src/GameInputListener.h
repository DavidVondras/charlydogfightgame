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

		bool _engineValueChanged;
		float _engineInputValue;

	protected:
		void ProcessEvent(sf::Event inputEvent, sf::RenderWindow &renderWindow);
		void OnListenCalled(sf::RenderWindow &renderWindow);

	public:
		GameInputListener(void);
		~GameInputListener(void);

		virtual bool IsGameListener(void) const sealed { return true; }

		bool getNavigateRightIsPressed() { return _navigateRightIsPressed; }
		bool getNavigateLeftIsPressed() { return _navigateLeftIsPressed; }
		bool getNavigateUpIsPressed() { return _navigateUpIsPressed; }
		bool getNavigateDownIsPressed() { return _navigateDownIsPressed; }

		bool getEngineValueChanged(void) { return _engineValueChanged; }
		float getEngineInputValue(void) { return _engineInputValue; }
	};
}


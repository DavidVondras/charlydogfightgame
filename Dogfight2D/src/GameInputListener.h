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

		bool _zoomInIsPressed;
		bool _zoomOutIsPressed;

		bool _torqueLeftIsPressed;
		bool _torqueRightIsPressed;

		bool _engineValueChanged;
		float _engineInputValue;

	protected:
		void ProcessEvent(sf::Event inputEvent, sf::RenderWindow &renderWindow);
		void OnListenCalled(sf::RenderWindow &renderWindow);

	public:
		GameInputListener(void);
		~GameInputListener(void);

		virtual bool IsGameListener(void) const sealed { return true; }

		bool getNavigateRightIsPressed(void) const { return _navigateRightIsPressed; }
		bool getNavigateLeftIsPressed(void) const { return _navigateLeftIsPressed; }
		bool getNavigateUpIsPressed(void) const { return _navigateUpIsPressed; }
		bool getNavigateDownIsPressed(void) const { return _navigateDownIsPressed; }

		bool getZoomInIsPressed(void) const { return _zoomInIsPressed; }
		bool getZoomOutIsPressed(void) const { return _zoomOutIsPressed; }

		bool getTorqueLeftIsPressed() const { return _torqueLeftIsPressed; }
		bool getTorqueRightIsPressed() const { return _torqueRightIsPressed; }

		bool getEngineValueChanged(void) const { return _engineValueChanged; }
		float getEngineInputValue(void) const { return _engineInputValue; }
	};
}


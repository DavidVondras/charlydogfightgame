#pragma once
#include <SFML\Graphics.hpp>

namespace df
{
	class InputListener
	{
	protected:
		virtual void ProcessEvent(sf::Event inputEvent, sf::RenderWindow &renderWindow) = 0;
		virtual void OnListenCalled(sf::RenderWindow &renderWindow) = 0;

	public:
		InputListener(void);
		~InputListener(void);

		virtual bool IsGameListener(void) const { return false; }
		void Listen(sf::RenderWindow &renderWindow);
	};
}


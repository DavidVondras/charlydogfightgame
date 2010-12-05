#pragma once
#include <SFML\Graphics.hpp>

namespace df
{
	class InputListener
	{
	protected:
		virtual void ProcessEvent(sf::Event inputEvent, sf::RenderWindow &renderWindow) = 0;

	public:
		InputListener(void);
		~InputListener(void);

		void Listen(sf::RenderWindow &renderWindow);
	};
}


#pragma once
#include <SFML\Graphics.hpp>

namespace df
{
	class Context
	{
	private:
		static float _ellapsedTime;

	public:
		static float getEllapsedTime() { return _ellapsedTime; }

		// Extracts the render window properties to update the context
		static void ExtractRenderWindowStatus(sf::RenderWindow const &renderWindow);
	};
}
#pragma once
#include <SFML\Graphics.hpp>
#include "PointStruct.h"
#include "SizeStruct.h"

namespace df
{
	class Context
	{
	private:
		static float _ellapsedTime;
		static df::SizeStructInt _windowSize;

	public:
		// Time ellapsed in last frame
		static float getEllapsedTime(void) { return _ellapsedTime; }

		// Actual size of the current window
		static df::SizeStructInt getWindowSize(void) { return _windowSize; }

		// Extracts the render window properties to update the context
		static void ExtractRenderWindowStatus(sf::RenderWindow const &renderWindow);
	};
}
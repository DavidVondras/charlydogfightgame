#pragma once
#include <SFML\Graphics.hpp>
#include "PointStruct.h"
#include "SizeStruct.h"
#include "PropertyListener.h"

namespace df
{
	class Context
	{
	private:
		static float _ellapsedTime;
		static float _frameRate;
		static df::SizeStructInt _windowSize;

	public:
		// Time ellapsed in last frame
		static const float& getEllapsedTime(void) { return _ellapsedTime; }

		// Get the actual fram rate
		static const float& getFrameRate(void) { return _frameRate; }

		// Actual size of the current window
		static const df::SizeStructInt& getWindowSize(void) { return _windowSize; }

		// Extracts the render window properties to update the context
		static void ExtractRenderWindowStatus(sf::RenderWindow const &renderWindow);

		// Add context properties in property listener
		static void AddInPropertyListener(void);
	};
}
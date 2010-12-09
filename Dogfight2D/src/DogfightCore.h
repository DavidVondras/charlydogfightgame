#pragma once
#include <SFML\System.hpp>
#include <Box2D\Box2D.h>
#include "Config.h"
#include "ListHelper.h"

namespace df
{
	// Point definition
	struct Point
	{
		// Initializes a point with (0;0)
		Point() : X(0.f), Y(0.f) {}

		// Initializes a point with specific coordinates
		Point(float x, float y) : X(x), Y(y) {}

		// Initializes a point from pixel point
		Point(sf::Vector2f pixelPoint): 
			X(pixelPoint.x / PixelPerMeterCoef),
			Y(- pixelPoint.y / PixelPerMeterCoef) {}
		
		// Initializes a point from physic meter point
		Point(b2Vec2 meterPoint):
			X(meterPoint.x),
			Y(meterPoint.y) {}

		// X coordinate
		float X;

		// Y coordinate
		float Y;

		// Transforms the current point into pixels
		sf::Vector2f ToPixel(void) { return sf::Vector2f(X * PixelPerMeterCoef, -Y  *PixelPerMeterCoef); }

		// Transforms the current point into physic meter
		b2Vec2 ToMeter(void) { return b2Vec2(X, Y); }

		// Set the current point from a pixel point
		void FromPixel(sf::Vector2f pixelPoint)
		{
			X = pixelPoint.x / PixelPerMeterCoef;
			Y = - pixelPoint.y / PixelPerMeterCoef;
		}

		// Set the current point from a physic meter point
		void FromMeter(b2Vec2 meterPoint)
		{
			X = meterPoint.x;
			Y = meterPoint.y;
		}
	};


	// Size definition
	struct Size
	{
		Size() : Width(0.f), Height(0.f) {}
		Size(float width, float height) : Width(width), Height(height) {}
		float Width;
		float Height;
	};
}
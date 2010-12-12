#pragma once
#include <SFML\System.hpp>
#include <Box2D\Box2D.h>
#include "Config.h"

namespace df
{
	// Point definition
	class Point
	{
	private:
		struct PointStruct { 
			PointStruct():X(0.f), Y(0.f){}
			PointStruct(const float &x, const float &y):X(x), Y(y){} 
			float X, Y; 
		} _meterValue, _pixelValue;
		bool _hasMeterValue, _hasPixelValue;

		void UpdateMeterValue(void) 
		{
			_meterValue.X = _pixelValue.X / PixelPerMeterCoef;
			_meterValue.Y = -_pixelValue.Y / PixelPerMeterCoef;
			_hasMeterValue = true;
		}

		void UpdatePixelValue(void) 
		{
			_pixelValue.X = _meterValue.X * PixelPerMeterCoef;
			_pixelValue.Y = -_meterValue.Y * PixelPerMeterCoef;
			_hasPixelValue = true;
		}

	public:
		// Initializes a point with (0;0)
		Point() : _meterValue(PointStruct()), _pixelValue(PointStruct()), _hasMeterValue(true), _hasPixelValue(true) {}

		// Initializes a point from pixel point
		Point(sf::Vector2f pixelPoint): 
		_pixelValue(PointStruct(pixelPoint.x, pixelPoint.y)), _hasMeterValue(false), _hasPixelValue(true) {} 
		
		// Initializes a point from physic meter point
		Point(b2Vec2 meterPoint):
			_meterValue(PointStruct(meterPoint.x, meterPoint.y)), _hasMeterValue(true), _hasPixelValue(false) {} 

		// Get the Pixel value
		sf::Vector2f ToPixel(void)
		{
			if(!_hasPixelValue) UpdatePixelValue();
			return sf::Vector2f(_pixelValue.X, _pixelValue.Y);
		}

		// Get the meter value
		b2Vec2 ToMeter(void) 
		{
			if(!_hasMeterValue) UpdateMeterValue();
			return b2Vec2(_meterValue.X, _meterValue.Y);
		}

		// Set the current point from a pixel point
		void SetPixel(sf::Vector2f pixelPoint)
		{
			_pixelValue = PointStruct(pixelPoint.x, pixelPoint.y);
			_hasPixelValue = true;
			_hasMeterValue = false;
		}

		// Set the current point from a pixel point
		void SetPixel(const float &x, const float &y)
		{
			_pixelValue = PointStruct(x, y);
			_hasPixelValue = true;
			_hasMeterValue = false;
		}

		// Set the current point from a physic meter point
		void SetMeter(b2Vec2 meterPoint)
		{
			_meterValue = PointStruct(meterPoint.x, meterPoint.y);
			_hasMeterValue = true;
			_hasPixelValue = false;
		}

		// Set the current point from a physic meter point
		void SetMeter(const float &x, const float &y)
		{
			_meterValue = PointStruct(x, y);
			_hasMeterValue = true;
			_hasPixelValue = false;
		}

		// Creates a point from  pixel value
		static Point FromPixel(const sf::Vector2f &pixelPoint)
		{
			Point point;
			point.SetPixel(pixelPoint);
			return point;
		}

		// Creates a point from  pixel value
		static Point FromPixel(const float &x, const float &y)
		{
			Point point;
			point.SetPixel(x, y);
			return point;
		}

		// Creates a point from  meter value
		static Point FromMeter(const b2Vec2 &meterPoint)
		{
			Point point;
			point.SetMeter(meterPoint);
			return point;
		}

		// Creates a point from  meter value
		static Point FromMeter(const float &x, const float &y)
		{
			Point point;
			point.SetMeter(x, y);
			return point;
		}
	};
}
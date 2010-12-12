#pragma once
#include "Config.h"

namespace df
{
	class Angle
	{
	private:
		float _degreeValue, _radianValue;
		bool _hasDegreeValue, _hasRadianValue;

		float UpdateRadianValue(void) 
		{
			_radianValue = _degreeValue*PI/180.f;
			_hasRadianValue = true;
			return _radianValue;
		}

		float UpdateDegreeValue(void)
		{
			_degreeValue = _radianValue*180.f/PI;
			_hasDegreeValue = true;
			return _degreeValue;
		}

	public:
		Angle(void): _degreeValue(0), _radianValue(0), _hasDegreeValue(true), _hasRadianValue(true){}
	
		// Get the angle in degree
		float ToDegree(void) { return _hasDegreeValue ? _degreeValue : UpdateDegreeValue(); }
		
		// Get rge angle in radian
		float ToRadian(void) { return _hasRadianValue ? _radianValue : UpdateRadianValue(); }

		// Set the angle with the degree value
		void SetDegree(const float value)
		{
			_degreeValue = value;
			_hasDegreeValue = true;
			_hasRadianValue = false;
		}

		// Set the angle with a radian value
		void SetRadian(const float value)
		{
			_radianValue = value;
			_hasRadianValue = true;
			_hasDegreeValue = false;
		}

		// Creates an angle from Degree value
		static Angle FromDegree(const float &value) 
		{
			Angle angle;
			angle.SetDegree(value);
			return angle;
		}

		// Creates an angle from radian value
		static Angle FromRadian(const float &value)
		{
			Angle angle;
			angle.SetRadian(value);
			return angle;
		}

		Angle operator+ (Angle &value) 
		{
			return _hasDegreeValue ?
				Angle::FromDegree(_degreeValue + value.ToDegree()) :
				Angle::FromRadian(_radianValue + value.ToRadian());
		}

		Angle operator- (Angle &value) 
		{
			return _hasDegreeValue ?
				Angle::FromDegree(_degreeValue - value.ToDegree()) :
				Angle::FromRadian(_radianValue - value.ToRadian());
		}
	};
}
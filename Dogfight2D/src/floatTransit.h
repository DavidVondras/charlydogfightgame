#pragma once
#include<cmath>

namespace df
{
	class floatTransit
	{
	private:
		float _value;
		float _target;
		bool _isAsleep;
		float _errorDelta;
		float _velocityCoefficient;

	public:
		floatTransit(void) :
		  _value(0.f), _target(0.f), _isAsleep(true), _errorDelta(0.001f), _velocityCoefficient(1.f) {}
		floatTransit(float initValue, float errorDelta, float velocityCoefficient) :
		  _value(initValue), _target(initValue), _isAsleep(true), _errorDelta(errorDelta) , _velocityCoefficient(velocityCoefficient) {}

		// Get the actual float value
		float getValue(void) const { return _value; }
		
		// Force the value
		void setValue(float value) { _value = _target = value; _isAsleep = true; }

		// Set the float target
		void setTarget(float value) { _target = value; _isAsleep = false; }
		
		// Get the float target
		float getTarget(void) const { return _target; }
		
		// Determines the error delta
		void setErrorDelta(float value) { _errorDelta = value; }
		
		// Set the velocity coefficient to reach the target value
		void setVelocityCoefficient(float value) { _velocityCoefficient = value; }
		
		// Perform a step
		void Step(float ellapsedTime) 
		{ 
			if(!_isAsleep) 
			{
				_value += (_target - _value)*ellapsedTime*_velocityCoefficient/2.f;
				if(std::abs(_target - _value) < _errorDelta)
				{
					_isAsleep = true;
					_value = _target;
				}
			}
		}

		// Equal operator overloading from float
		df::floatTransit operator= (const float& value)
		{
			_target = value;
			_isAsleep = false;
			return *this;
		}
		
		// += operator overloading from float
		df::floatTransit operator+=(const float& value)
		{
			_target += value;
			_isAsleep = false;
			return *this;
		}

		// -= operator overloading from float
		df::floatTransit operator-=(const float& value)
		{
			_target -= value;
			_isAsleep = false;
			return *this;
		}
	};
}
#pragma once

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

		float getValue(void) const { return _value; }
		void setTarget(float value) { _target = value; _isAsleep = false; }
		float getTarget(void) const { return _target; }
		void setValue(float value) { _value = _target = value; _isAsleep = true; }
		void setErrorDelta(float value) { _errorDelta = value; }
		void setVelocityCoefficient(float value) { _velocityCoefficient = value; }
		void Step(float ellapsedTime) 
		{ 
			if(!_isAsleep) 
			{
				_value += (_target - _value)*ellapsedTime*_velocityCoefficient/2.f;
				if(_value < _errorDelta)
				{
					_isAsleep = true;
					_value = _target;
				}
			}
		}

		// Equal operator overloading from float
		df::floatTransit operator= (const float& value)
		{
			_target = _value = value;
			_isAsleep = true;
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
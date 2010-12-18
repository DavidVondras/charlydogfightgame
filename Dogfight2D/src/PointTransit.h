#pragma once
#include "floatTransit.h"
#include "PointStruct.h"

namespace
{
	class PointTransit
	{
	private:
		df::floatTransit _x,_y;

	public:
		PointTransit(){}
		PointTransit(float errorDelta, float velocityCoefficient)
		{
			_x.setVelocityCoefficient(velocityCoefficient);
			_y.setVelocityCoefficient(velocityCoefficient);
			_x.setErrorDelta(errorDelta);
			_y.setErrorDelta(errorDelta);
		}

		df::PointStruct getValue(void) const { return df::PointStruct(_x.getValue(), _y.getValue()); }
		void setValue(float x, float y) { _x.setValue(x); _y.setValue(y); }

		df::PointStruct getTarget(void) const { return df::PointStruct(_x.getTarget(), _y.getTarget()); }
		void setTarget(float x, float y) { _x.setTarget(x); _y.setTarget(y); }

		void setErrorDelta(float value) { _x.setErrorDelta(value); _y.setErrorDelta(value); }
		void setVElocityCoefficient(float value) { _x.setVelocityCoefficient(value); _y.setVelocityCoefficient(value); }

		void Step(float ellapsedTime) { _x.Step(ellapsedTime); _y.Step(ellapsedTime); }
	};
}
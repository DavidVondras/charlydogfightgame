#pragma once
#include <Box2D\Box2D.h>
#include <list>
#include "DogfightCore.h"
#include "StepableObject.h"

namespace df
{
	class PhysicObject
		:public df::StepableObject
	{
	protected:
		b2Body *_physicBody;
		std::list<df::Point*> _boundaryPoints;

	public:
		virtual ~PhysicObject(void) {};

		virtual void RegisterToPhysicWorld(b2World &world) = 0;

		virtual bool IsPhysicObject(void) sealed { return true; }
	};
}


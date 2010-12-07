#pragma once
#include <Box2D\Box2D.h>
#include <list>
#include "DogfightCore.h"

namespace df
{
	class BoundableObject
	{
	protected:
		b2Body *physicBody;
		std::list<df::Point> _boundaryPoints;

	public:
		BoundableObject(void);
		~BoundableObject(void);
	};
}


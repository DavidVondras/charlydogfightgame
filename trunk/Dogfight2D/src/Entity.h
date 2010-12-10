#pragma once
#include <Box2D\Box2D.h>
#include "StepableObject.h"

namespace df
{
	class Entity: public df::StepableObject
	{
	protected:
		b2Body *physicBody;
	public:
		virtual void Think(df::InputListener const &inputListner) = 0;
		virtual void Draw(sf::RenderWindow &renderWindow) = 0;
	};
}
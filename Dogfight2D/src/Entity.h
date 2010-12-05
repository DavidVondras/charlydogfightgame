#pragma once
#include <Box2D\Box2D.h>
#include "IStepable.h"

namespace df
{
	class Entity: public df::IStepable
	{
	protected:
		b2Body *physicBody;
	public:
		virtual void Think(df::InputListener const &inputListner) = 0;
		virtual void Draw(sf::RenderWindow &renderWindow) = 0;
	};
}
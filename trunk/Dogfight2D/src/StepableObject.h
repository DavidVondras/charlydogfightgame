#pragma once
#include <SFML\Graphics.hpp>
#include "InputListener.h"
#include "DogfightCore.h"

namespace df
{
	class StepableObject
	{
	public:
		virtual ~StepableObject() {};

		virtual void Think(df::InputListener const &inputListner) = 0;
		virtual void Draw(sf::RenderWindow &renderWindow) = 0;

		df::Point _position;
		df::Angle _rotation;

		// Object Type identifier
		virtual bool IsPhysicObject(void) { return false; }
	};
}
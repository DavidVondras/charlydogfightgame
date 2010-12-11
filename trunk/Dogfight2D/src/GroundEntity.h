#pragma once
#include "DogfightCore.h"
#include "PhysicObject.h"

namespace df
{
	class GroundEntity: 
		public df::PhysicObject
	{
	public:
		GroundEntity(void);
		~GroundEntity(void);

		void RegisterToPhysicWorld(b2World &world);
		void Think(df::InputListener const &inputListner);
		void Draw(sf::RenderWindow &renderWindow);
	};
}

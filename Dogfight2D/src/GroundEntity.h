#pragma once
#include "DogfightCore.h"
#include "IStepable.h"
#include "BoundableObject.h"

namespace df
{
	class GroundEntity: 
		public df::IStepable,
		public df::BoundableObject
	{
	public:
		GroundEntity(void);
		~GroundEntity(void);

		void Think(df::InputListener const &inputListner);
		void Draw(sf::RenderWindow &renderWindow);
	};
}


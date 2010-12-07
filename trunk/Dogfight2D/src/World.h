#pragma once
#include "IStepable.h"
#include "WorldDefinition.h"
#include "GroundEntity.h"

namespace df
{
	class World: public df::IStepable
	{
	private:
		WorldDefinition _tempDef;
		df::GroundEntity _groundEntity;
		df::IStepable *_actor;

	public:
		World(void);
		~World(void);

		void Initialize(df::WorldDefinition const worldDefinition);
		void Think(df::InputListener const &inputListner);
		void Draw(sf::RenderWindow &renderWindow);
	};
}


#pragma once
#include "DogfightCore.h"
#include "StepableObject.h"
#include "WorldDefinition.h"
#include "GroundEntity.h"
#include <Box2D\Box2D.h>
#include <list>

namespace df
{
	class World: public df::StepableObject
	{
	private:
		// Temporary objects
		WorldDefinition _tempDef;
		df::GroundEntity _groundEntity;
		
		// Physic engine world instance
		b2World *_physicWorld;

		// List of existing objects entities
		std::list<df::StepableObject*> _stepableObjects;

		// Specific object references
		df::StepableObject *_actor;

	public:
		World(void);
		~World(void);

		// Initialization
		void Initialize(const df::WorldDefinition worldDefinition);

		// Get the actor instance
		df::StepableObject* getActor(void) const { return _actor; }

		// IStepable methods
		void Think(const df::InputListener &inputListner);
		void Draw(sf::RenderWindow &renderWindow);
	};
}


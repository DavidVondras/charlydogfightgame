#pragma once
#include <stdlib.h>
#include <SFML\Graphics.hpp>
#include "GameInputListener.h"
#include "ObjectDefinitionLoader.h"
#include "World.h"
#include "IScreen.h"
#include "Entity.h"

namespace df
{
	class Game: public df::IScreen
	{
	private:
		// df instances
		df::GameInputListener _inputListener;
		df::World _world;
		
		// sf RenderWindow (owned by Main)
		sf::RenderWindow &_renderWindow;

		// Actor view definition (owner)
		struct
		{
			// Sf view instance
			sf::View View;

			// Current velocity of the view 
			df::Point Velocity;

			// Targeted entity. If null, the view is in free mode.
			// In free mode, view is controled directly by user.
			df::Entity *targetedEntity;
		} _actorViewDefinition;

		// Refreshes the view
		void ComputeActorView(void);

	public:
		// Initialization
		Game(sf::RenderWindow &renderWindow);
		~Game(void);

		// Properties
		InputListener& getInputListener(void) { return _inputListener; }

		// Public methods
		int Initialize(std::string sceneryName);
		void Step(void);
	};
}

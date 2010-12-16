#pragma once
#include <stdlib.h>
#include <SFML\Graphics.hpp>
#include "GameInputListener.h"
#include "ObjectDefinitionLoader.h"
#include "World.h"
#include "IScreen.h"

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

		// TODO: create a specific object to manage these peaces of view information
		// Game view definition
		struct {
			sf::View View; // Sf view instance
			df::floatTransit Zoom; // Zoom
			struct { df::floatTransit X, Y; } Position;
			void Step(float ellapsedTime){
				Position.X.Step(ellapsedTime), Position.Y.Step(ellapsedTime);
				View.SetCenter(Position.X.getValue(), Position.Y.getValue()); }
			// Targeted entity. If null, the view is in free mode.
			// In free mode, view is controled directly by user.
			df::StepableObject *targetedEntity;
		} _gameViewDefinition;

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


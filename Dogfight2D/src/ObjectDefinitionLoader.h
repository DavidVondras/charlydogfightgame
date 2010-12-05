#pragma once
#include <iostream>
#include <stdlib.h>
#include "ArrayHelper.h"
#include "WorldDefinition.h"
#include "FileHelper.h"

namespace df
{
	class ObjectDefinitionLoader
	{
	public:
		ObjectDefinitionLoader(void) { }
		~ObjectDefinitionLoader(void) { }

		static int LoadWorldDefinition(df::WorldDefinition &worldDefinition, std::string sceneryName)
		{
			// Initializes world definition as dirty by default
			worldDefinition.IsDirty = true;
			worldDefinition.GroundPointsNb = 0;

			// Populate GroundPoints with mockup data
			ArrayHelper::Add<df::Point>(worldDefinition.GroundPoints, df::Point(0.f,10.f), worldDefinition.GroundPointsNb, df::WorldDefinition::GroundPointsNbMax);
			ArrayHelper::Add<df::Point>(worldDefinition.GroundPoints, df::Point(60.f,10.f), worldDefinition.GroundPointsNb, df::WorldDefinition::GroundPointsNbMax);
			ArrayHelper::Add<df::Point>(worldDefinition.GroundPoints, df::Point(65.f,13.f), worldDefinition.GroundPointsNb, df::WorldDefinition::GroundPointsNbMax);
			ArrayHelper::Add<df::Point>(worldDefinition.GroundPoints, df::Point(70.f,10.f), worldDefinition.GroundPointsNb, df::WorldDefinition::GroundPointsNbMax);
			ArrayHelper::Add<df::Point>(worldDefinition.GroundPoints, df::Point(200.f,10.f), worldDefinition.GroundPointsNb, df::WorldDefinition::GroundPointsNbMax);
			
			// As the world have been loaded until the end, it is no more dirty
			worldDefinition.IsDirty = false;
			return EXIT_SUCCESS;
		}
	};
}


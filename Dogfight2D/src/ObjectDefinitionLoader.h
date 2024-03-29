#pragma once
#include <iostream>
#include <stdlib.h>
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
			worldDefinition.TreeNb = 0;

			// Populate GroundPoints with mockup data
			worldDefinition.AddGroundPoint(df::Point::FromMeter(0.f,10.f));
			worldDefinition.AddGroundPoint(df::Point::FromMeter(200.f,10.f));

			// Populate Trees with mockup data
			worldDefinition.AddTree(df::Point::FromMeter(80.f,10.f));
			
			// As the world have been loaded until the end, it is no more dirty
			worldDefinition.IsDirty = false;
			return EXIT_SUCCESS;
		}
	};
}


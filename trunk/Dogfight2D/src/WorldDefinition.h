#pragma once
#include <string>
#include "DogfightCore.h"

namespace df
{
	struct WorldDefinition
	{
		// Constantes
		const static int GroundPointsNbMax = 1024;
		const static int TreeNbMax = 1024;

		// Common properties
		int IsDirty;

		// Ground points
		df::Point GroundPoints[GroundPointsNbMax];
		int GroundPointsNb;

		// Trees
		df::Point Trees[TreeNbMax];
		int TreeNb;
	};
}
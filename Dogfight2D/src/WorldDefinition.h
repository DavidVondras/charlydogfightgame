#pragma once
#include <string>
#include "DogfightCore.h"
#include "ArrayHelper.h"

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
		void AddGroundPoint(df::Point point) { ArrayHelper::Add<df::Point>(GroundPoints, point, GroundPointsNb, GroundPointsNbMax); }

		// Trees
		df::Point Trees[TreeNbMax];
		int TreeNb;
		void AddTree(df::Point point) { ArrayHelper::Add<df::Point>(Trees, point, TreeNb, TreeNbMax); }
	};
}
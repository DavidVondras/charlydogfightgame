#include "World.h"

df::World::World(void)
{
}


df::World::~World(void)
{
}

void df::World::Initialize(df::WorldDefinition const worldDefinition)
{
	_tempDef = worldDefinition;
}

void df::World::Think(df::InputListener const &inputListner)
{

}

void df::World::Draw(sf::RenderWindow &renderWindow)
{
	// Render the ground
	sf::Shape groundShape;
	groundShape.SetColor(sf::Color(0,200,0));
	groundShape.AddPoint(_tempDef.GroundPoints[0].ToPixel().x, 200.f);
	int i=0;
	for(; i<_tempDef.GroundPointsNb; i++)
	{
		groundShape.AddPoint(_tempDef.GroundPoints[i].ToPixel());
	}
	groundShape.AddPoint(_tempDef.GroundPoints[i-1].ToPixel().x, 200.f);
	renderWindow.Draw(groundShape);

	// TODO render the trees
}
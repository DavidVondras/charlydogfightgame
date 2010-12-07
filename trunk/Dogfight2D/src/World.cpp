#include "World.h"
#include "JetEntity.h"

df::World::World(void)
{
	_actor = NULL;
}


df::World::~World(void)
{
	if(_actor != NULL)
	{
		delete _actor;
		_actor = NULL;
	}
}

void df::World::Initialize(df::WorldDefinition const worldDefinition)
{
	_tempDef = worldDefinition;
	_actor = new df::JetEntity();
}

void df::World::Think(df::InputListener const &inputListner)
{
	_actor->Think(inputListner);
}

void df::World::Draw(sf::RenderWindow &renderWindow)
{
	// Render the ground
	sf::Shape groundShape;
	groundShape.SetColor(sf::Color(0,200,0));
	groundShape.AddPoint(_tempDef.GroundPoints[0].ToPixel().x, 200.f);
	{
		int i=0;
		for(; i<_tempDef.GroundPointsNb; i++)
		{
			groundShape.AddPoint(_tempDef.GroundPoints[i].ToPixel());
		}
		groundShape.AddPoint(_tempDef.GroundPoints[i-1].ToPixel().x, 200.f);
	}
	renderWindow.Draw(groundShape);

	// TODO: Render the trees

	// Render the actor
	_actor->Draw(renderWindow);
}
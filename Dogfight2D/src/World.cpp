#include "World.h"
#include "JetEntity.h"
#include "Context.h"

df::World::World(void)
{
}


df::World::~World(void)
{
	delete _actor;
	delete _physicWorld;
}

void df::World::Initialize(df::WorldDefinition const worldDefinition)
{
	// world definition temporary backup
	_tempDef = worldDefinition;
	
	{	// World creation
		b2Vec2 gravity(0.0f, -10.0f);
		bool doSleep = true;
		_physicWorld = new b2World(gravity, doSleep);
	}
		
	// Actor creation
	df::JetEntity *jetEntity = new df::JetEntity();
	_actor = jetEntity;
	jetEntity->RegisterToPhysicWorld(*_physicWorld);
}

void df::World::Think(df::InputListener const &inputListner)
{
	_actor->Think(inputListner);
	_physicWorld->Step(df::Context::getEllapsedTime(), 6, 2);
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
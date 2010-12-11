#include "World.h"
#include "JetEntity.h"
#include "Context.h"

df::World::World(void)
{
}


df::World::~World(void)
{
	df::ListHelper::ClearListPointer<df::StepableObject>(_stepableObjects);
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
	_stepableObjects.push_back(jetEntity);
	_actor = jetEntity;

	// Register physic object
	foreach(df::StepableObject*, _stepableObjects)
	{
		if((*i)->IsPhysicObject())
		{
			((df::PhysicObject*)(*i))->RegisterToPhysicWorld(*_physicWorld);
		}
	}

	b2BodyDef groundBodyDef;
	groundBodyDef.position = df::Point(0.f, 10.f).ToMeter();
	b2Body* groundBody = _physicWorld->CreateBody(&groundBodyDef);
	b2PolygonShape groundBox;
	groundBox.SetAsEdge(df::Point(0.f,0.f).ToMeter(), df::Point(200.f, 0.f).ToMeter());
	groundBody->CreateFixture(&groundBox, 1.f);
}

void df::World::Think(df::InputListener const &inputListner)
{
	// Perform stepable think()
	foreach(df::StepableObject*, _stepableObjects)
	{
		(*i)->Think(inputListner);
	}

	// Step physic world
	_physicWorld->Step(df::Context::getEllapsedTime(), 6, 2);
}

void df::World::Draw(sf::RenderWindow &renderWindow)
{
	// Render the ground
	sf::Shape groundShape;
	groundShape.SetColor(sf::Color(0,200,0));
	groundShape.AddPoint(_tempDef.GroundPoints[0].ToPixel().x, 0.f);
	{
		int i=0;
		for(; i<_tempDef.GroundPointsNb; i++)
		{
			groundShape.AddPoint(_tempDef.GroundPoints[i].ToPixel());
		}
		groundShape.AddPoint(_tempDef.GroundPoints[i-1].ToPixel().x, 0.f);
	}
	renderWindow.Draw(groundShape);

	// TODO: Render the trees

	// Render the actor
	_actor->Draw(renderWindow);
}
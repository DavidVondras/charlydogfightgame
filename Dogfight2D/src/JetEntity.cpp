#include "JetEntity.h"
#include <iostream>


df::JetEntity::JetEntity(void)
{
	// Initialize sprite image
	std::string objectsFolder = ObjectsFolder;
	if (!_image.LoadFromFile(objectsFolder + "jet1\\plane.png"))
	{
		std::cerr<<"Error while loading jet image!"<<std::endl;
		return;
	}
	_sprite.SetImage(_image);

	// Initialize position
	_position.X = 50.f;
	_position.Y = 30.f;

	// Create the boudary
	_boundaryPoints.push_back(new df::Point(-80.f, 25.f));
	_boundaryPoints.push_back(new df::Point(80.f, 20.f));
	_boundaryPoints.push_back(new df::Point(80.f, -20.f));
	_boundaryPoints.push_back(new df::Point(-80.f, -20.f));

	// Initialize physic body instance
	_physicBody = NULL;
}


df::JetEntity::~JetEntity(void)
{
	ListHelper::ClearListPointer(_boundaryPoints);
}

void df::JetEntity::RegisterToPhysicWorld(b2World &world)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position = _position.ToMeter();
	_physicBody = world.CreateBody(&bodyDef);
}

void df::JetEntity::Think(df::InputListener const &inputListner)
{
	// Update position
	_position.FromMeter(_physicBody->GetPosition());
}

void df::JetEntity::Draw(sf::RenderWindow &renderWindow)
{
	_sprite.SetPosition(_position.ToPixel());
	renderWindow.Draw(_sprite);
}
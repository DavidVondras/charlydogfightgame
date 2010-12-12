#include "TreeEntity.h"
#include "Config.h"
#include <iostream>


df::TreeEntity::TreeEntity(void)
{
	std::string objectsFolder = ObjectsFolder;
	if (!_image.LoadFromFile(objectsFolder + "tree1\\tree.png"))
	{
		std::cerr<<"Error while loading tree image!"<<std::endl;
		return;
	}
	_sprite.SetImage(_image);
	_position.SetMeter(50.f, 30.f);
}


df::TreeEntity::~TreeEntity(void)
{
}

void df::TreeEntity::RegisterToPhysicWorld(b2World &world)
{
}

void df::TreeEntity::Think(df::InputListener const &inputListner)
{
	// TODO
}

void df::TreeEntity::Draw(sf::RenderWindow &renderWindow)
{
	_sprite.SetPosition(_position.ToPixel());
	renderWindow.Draw(_sprite);
}
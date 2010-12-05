#include "JetEntity.h"
#include "Config.h"
#include <iostream>


df::JetEntity::JetEntity(void)
{
	std::string objectsFolder = ObjectsFolder;
	if (!_image.LoadFromFile(objectsFolder + "jet1\\plane.png"))
	{
		std::cerr<<"Error while loading jet image!"<<std::endl;
		return;
	}
	_sprite.SetImage(_image);
	_position.X = 50.f;
	_position.Y = 30.f;
}


df::JetEntity::~JetEntity(void)
{
}

void df::JetEntity::Think(df::InputListener const &inputListner)
{

}

void df::JetEntity::Draw(sf::RenderWindow &renderWindow)
{
	_sprite.SetPosition(_position.ToPixel());
	renderWindow.Draw(_sprite);
}
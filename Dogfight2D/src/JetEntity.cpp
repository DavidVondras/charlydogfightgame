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
	_position.X = 30.f;
	_position.Y = 30.f;
	_rotation = ConvertDegreeIntoRadian(30);

	// Create the boundary
	_boundaryPoints.push_back(new df::Point(sf::Vector2f(0.f, 45.f)));
	_boundaryPoints.push_back(new df::Point(sf::Vector2f(160.f, 40.f)));
	_boundaryPoints.push_back(new df::Point(sf::Vector2f(160.f, 0.f)));
	_boundaryPoints.push_back(new df::Point(sf::Vector2f(0.f, 0.f)));
	
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
	bodyDef.angle = _rotation;
	_physicBody = world.CreateBody(&bodyDef);

	b2PolygonShape shape;
	b2Vec2 vertices[8];
	int currentIndex = 0;
	foreach(df::Point*, _boundaryPoints) vertices[currentIndex++] = (*i)->ToMeter();
	shape.Set(vertices, _boundaryPoints.size());
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	_physicBody->CreateFixture(&fixtureDef);
	b2MassData massData;
	_physicBody->GetMassData(&massData);
	massData.mass = 1000.f;
	std::cout<<"jet mass = "<<massData.mass<<std::endl;
	std::cout<<"jet center of mass = "<<massData.center.x<<"; "<<massData.center.y<<std::endl;
	std::cout<<"jet intertia = "<<massData.I<<std::endl;
}

void df::JetEntity::Think(df::InputListener const &inputListner)
{
	// Update position
	_position.FromMeter(_physicBody->GetPosition());
	_rotation = _physicBody->GetAngle();
}

void df::JetEntity::Draw(sf::RenderWindow &renderWindow)
{
	// Sprite
	_sprite.SetPosition(_position.ToPixel());
	_sprite.SetRotation(ConvertRadianIntoDegree(_rotation));
	renderWindow.Draw(_sprite);

	// debug boundary
	sf::Shape boundShape;
	foreach(df::Point*, _boundaryPoints) boundShape.AddPoint(_sprite.TransformToGlobal((*i)->ToPixel() + _sprite.GetCenter()), sf::Color::Black, sf::Color(255,255,255,100));
	boundShape.SetOutlineWidth(1.f);
	boundShape.EnableOutline(true);
	boundShape.EnableFill(false);
	renderWindow.Draw(boundShape);

	// debug boudary vertices
	foreach(df::Point*, _boundaryPoints)
		renderWindow.Draw(sf::Shape::Circle(_sprite.TransformToGlobal((*i)->ToPixel() + _sprite.GetCenter()), 3.f, sf::Color::White));

	// debug center
	renderWindow.Draw(sf::Shape::Circle(_sprite.TransformToGlobal(df::Point(_physicBody->GetLocalCenter()).ToPixel() + _sprite.GetCenter()), 3.f, sf::Color::Yellow));
}
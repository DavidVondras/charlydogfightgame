#include "JetEntity.h"
#include "GameInputListener.h"
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
	_position.SetMeter(30.f, 30.f);
	_rotation = Angle::FromDegree(30);
	_engineValue = 0.f;

	// Create the boundary
	_boundaryPoints.push_back(new df::Point(sf::Vector2f(15.f, 53.f)));
	_boundaryPoints.push_back(new df::Point(sf::Vector2f(167.f, 52.f)));
	_boundaryPoints.push_back(new df::Point(sf::Vector2f(117.f, 27.f)));
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
	// Create body
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position = _position.ToMeter();
	bodyDef.angle = _rotation.ToRadian();
	_physicBody = world.CreateBody(&bodyDef);

	// Set body shape
	b2PolygonShape shape;
	b2Vec2 vertices[8];
	int currentIndex = 0;
	foreach(df::Point*, _boundaryPoints) vertices[currentIndex++] = (*i)->ToMeter();
	shape.Set(vertices, _boundaryPoints.size());
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.density = 10.0f;
	fixtureDef.friction = 0.3f;
	_physicBody->CreateFixture(&fixtureDef);

	// Set body mass data
	b2MassData newMassData;
	newMassData.mass = 1000.f;
	newMassData.center = df::Point(sf::Vector2f(86.f, 43.f)).ToMeter();
	newMassData.I = 80000.f;
	_physicBody->SetMassData(&newMassData);
}

void df::JetEntity::Think(const df::InputListener &inputListner)
{
	// Update position
	_position.SetMeter(_physicBody->GetPosition());
	_rotation.SetRadian(_physicBody->GetAngle());

	// Check inputs
	if(inputListner.IsGameListener())
	{
		df::GameInputListener *gameListener = (df::GameInputListener*)(&inputListner);
		if(gameListener->getEngineValueChanged())
		{
			_engineValue = gameListener->getEngineInputValue();
			std::cout<<"Engine: "<<_engineValue<<std::endl;
		}

		if(gameListener->getTorqueLeftIsPressed())
		{
			_physicBody->ApplyTorque(100000.f);
		}
		if(gameListener->getTorqueRightIsPressed())
		{
			_physicBody->ApplyTorque(-100000.f);
		}

		if(gameListener->getEngineValueChanged())
		{
			_engineValue = gameListener->getEngineInputValue();
		}

		_physicBody->ApplyForce(
			df::Point::FromMeter(0.f, 10000.f*_engineValue).ToMeter(),
			_position.ToMeter());
	}
}

void df::JetEntity::Draw(sf::RenderWindow &renderWindow)
{
	// Sprite
	_sprite.SetPosition(_position.ToPixel());
	_sprite.SetRotation(_rotation.ToDegree());
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
		renderWindow.Draw(sf::Shape::Circle(_sprite.TransformToGlobal((*i)->ToPixel()), 3.f, sf::Color::White));

	// debug center
	renderWindow.Draw(sf::Shape::Circle(_sprite.TransformToGlobal(df::Point(_physicBody->GetLocalCenter()).ToPixel()), 3.f, sf::Color::Yellow));
}
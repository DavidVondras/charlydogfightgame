#include "JetEntity.h"
#include "GameInputListener.h"
#include "MathHelper.h"
#include "Context.h"
#include <iostream>

/// Default Constructor
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
	_sprite.SetCenter(86.f, 43.f);

	// Initialize position
	_position.SetMeter(30.f, 30.f);
	_rotation = Angle::FromDegree(30);
	_engineValue = 0.f;

	// Create the boundary
	_boundaryPoints.push_back(new df::Point(sf::Vector2f(-71.f, 10.f)));
	_boundaryPoints.push_back(new df::Point(sf::Vector2f(81.f, 9.f)));
	_boundaryPoints.push_back(new df::Point(sf::Vector2f(31.f, -16.f)));
	_boundaryPoints.push_back(new df::Point(sf::Vector2f(-86.f, -43.f)));
	
	// Initialize physic body instance
	_physicBody = NULL;
}

/// Default destructor
df::JetEntity::~JetEntity(void)
{
	ListHelper::ClearListPointer(_boundaryPoints);
}

/// Adds references to the property listener
void df::JetEntity::AddInPropertyListener(void)
{
	df::PropertyListener::getInstance().AddProperty(&_debug_localVelocity_x, "localV : x=%+3.1f m/s");
	df::PropertyListener::getInstance().AddProperty(&_debug_localVelocity_y, "localV : y=%+3.1f m/s");
	df::PropertyListener::getInstance().AddProperty(&_cz, "Cz :%.1f");
	df::PropertyListener::getInstance().AddProperty(&_engineValue, "Engine :%.1f");
}

/// Physic initialization
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
	newMassData.mass = Mass;
	newMassData.center = df::Point(sf::Vector2f(0.f, 0.f)).ToMeter();
	newMassData.I = MassInertia;
	_physicBody->SetMassData(&newMassData);
}

/// Think frame step
void df::JetEntity::Think(const df::InputListener &inputListner)
{
	// Update position
	_position.SetMeter(_physicBody->GetPosition());
	_rotation.SetRadian(_physicBody->GetAngle());

	// Check inputs
	if(inputListner.IsGameListener())
	{
		// Update local fields according to inputs
		df::GameInputListener *gameListener = (df::GameInputListener*)(&inputListner);
		if(gameListener->getEngineValueChanged()) _engineValue = gameListener->getEngineInputValue();
		if(gameListener->getTorqueLeftIsPressed()) _physicBody->ApplyTorque(50000.f);
		if(gameListener->getTorqueRightIsPressed()) _physicBody->ApplyTorque(-50000.f);
		if(gameListener->getEngineValueChanged()) _engineValue = gameListener->getEngineInputValue();
	}

	// Compute velocities
	b2Vec2 globalVelocity = _physicBody->GetLinearVelocity();
	_localVelocity = df::Point::FromMeter(globalVelocity).ApplyReverseRotation(_rotation);
	_normalVelocity = std::sqrt(globalVelocity.x*globalVelocity.x + globalVelocity.y*globalVelocity.y);

	// Apply Engine force
	_physicBody->ApplyForce(
		df::Point::FromMeter(EngineStrengthCoefficient*_engineValue, 0.f).ApplyRotation(_rotation).ToMeter(),
		_position.ToMeter());
		
	// Apply Cz frictional strength
	_cz = df::MathHelper::PolyBezier(_normalVelocity, CzVelocityMin, 0.f, CzVelocityMax, 1.f);
	_physicBody->ApplyForce(
		df::Point::FromMeter(0.f, -_localVelocity.ToMeter().y*_cz*_physicBody->GetMass()*10).ApplyRotation(_rotation).ToMeter(),
		_position.ToMeter());

	// Set debug information
	_debug_localVelocity_x = _localVelocity.ToMeter().x;
	_debug_localVelocity_y = _localVelocity.ToMeter().y;
}

/// Draw Frame step
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
		renderWindow.Draw(sf::Shape::Circle(_sprite.TransformToGlobal((*i)->ToPixel() + _sprite.GetCenter()), 3.f, sf::Color::White));

	// debug center
	renderWindow.Draw(sf::Shape::Circle(_sprite.TransformToGlobal(df::Point(_physicBody->GetLocalCenter()).ToPixel() + _sprite.GetCenter()), 3.f, sf::Color::Yellow));
}
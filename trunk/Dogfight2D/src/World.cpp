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

void df::World::Initialize(const df::WorldDefinition worldDefinition)
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
	groundBodyDef.position = b2Vec2(0.f, 10.f);
	b2Body* groundBody = _physicWorld->CreateBody(&groundBodyDef);
	b2PolygonShape groundBox;
	groundBox.SetAsEdge(df::Point::FromMeter(0.f,0.f).ToMeter(), df::Point::FromMeter(200.f, 0.f).ToMeter());
	groundBody->CreateFixture(&groundBox, 1.f);
}

void df::World::Think(const df::InputListener &inputListner)
{
	// Perform stepable think()
	foreach(df::StepableObject*, _stepableObjects)
	{
		(*i)->Think(inputListner);
	}

	// Step physic world
	_physicWorld->Step(df::Context::getEllapsedTime(), 6, 2);
}

#define DebugLineHorizontalOffset 20.f
#define DebugLineVerticalOffset 50.f
#define DebugLineFontSize 12.f
void df::World::Draw(sf::RenderWindow &renderWindow)
{
	// Render the grid
	sf::View currentView = renderWindow.GetView();
	df::Point bottomLeftStart = df::Point::FromPixel(currentView.GetRect().Left, currentView.GetRect().Bottom);
	bottomLeftStart.SetMeter(
		((int)(bottomLeftStart.ToMeter().x / DebugLineVerticalOffset))*DebugLineVerticalOffset,
		((int)(bottomLeftStart.ToMeter().y / DebugLineHorizontalOffset))*DebugLineHorizontalOffset);
	df::Point TopRightEnd = df::Point::FromPixel(currentView.GetRect().Right, currentView.GetRect().Top);
	TopRightEnd.SetMeter(
		((int)(TopRightEnd.ToMeter().x / DebugLineVerticalOffset))*DebugLineVerticalOffset + DebugLineVerticalOffset,
		((int)(TopRightEnd.ToMeter().y / DebugLineHorizontalOffset))*DebugLineHorizontalOffset + DebugLineHorizontalOffset);

	// Create horizontal lines
	char stringBuffer[30];
	for(float i = bottomLeftStart.ToMeter().y; i < TopRightEnd.ToMeter().y; i+=DebugLineHorizontalOffset)
	{
		// Draw line
		renderWindow.Draw(sf::Shape::Line(
			currentView.GetRect().Left, -i*PixelPerMeterCoef,
			currentView.GetRect().Right, -i*PixelPerMeterCoef, 
			4.f, sf::Color(10, 10, 10, 255)));

		// Draw altitude
		sprintf_s(stringBuffer, "%i m", (int)i);
		sf::String shapeString = sf::String(stringBuffer, sf::Font::GetDefaultFont(), DebugLineFontSize);
		shapeString.SetPosition(currentView.GetRect().Left + 10.f, -i*PixelPerMeterCoef - 15.f);
		shapeString.SetColor(sf::Color(100,100,100,255));
		renderWindow.Draw(shapeString);
	}

	// Create vertical lines
	for(float i = bottomLeftStart.ToMeter().x; i < TopRightEnd.ToMeter().x; i+=DebugLineVerticalOffset)
	{
		// Draw line
		renderWindow.Draw(sf::Shape::Line(
			i*PixelPerMeterCoef, currentView.GetRect().Top,
			i*PixelPerMeterCoef, currentView.GetRect().Bottom,
			4.f, sf::Color(10, 10, 10, 255)));

		// Draw altitude
		sprintf_s(stringBuffer, "%i m", (int)i);
		sf::String shapeString = sf::String(stringBuffer, sf::Font::GetDefaultFont(), DebugLineFontSize);
		shapeString.SetPosition(i*PixelPerMeterCoef + 15.f, currentView.GetRect().Top + 10.f);
		shapeString.SetColor(sf::Color(100,100,100,255));
		renderWindow.Draw(shapeString);
	}

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
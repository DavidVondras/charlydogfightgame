#include "Game.h"
#include "Context.h"

df::Game::Game(sf::RenderWindow &renderWindow):
	_renderWindow(renderWindow)
{
}

df::Game::~Game(void)
{
}

int df::Game::Initialize(std::string sceneryName)
{
	// Compute screen half size
	sf::Vector2f screenHalfSize(_renderWindow.GetWidth() / 2.f,  _renderWindow.GetHeight() / 2.f);

	// Actor view Initialization
	_actorViewDefinition.targetedEntity = NULL;
	_actorViewDefinition.Velocity.X = 0;
	_actorViewDefinition.Velocity.Y = 0;
	_actorViewDefinition.View.SetCenter(screenHalfSize.x,-screenHalfSize.y);
	_actorViewDefinition.ZoomValue = 1.f;
	_actorViewDefinition.ZoomValue.setErrorDelta(0.001f);
	_actorViewDefinition.ZoomValue.setVelocityCoefficient(20.f);

	// Loading world definition
	df::WorldDefinition worldDefinition;
	if(df::ObjectDefinitionLoader::LoadWorldDefinition(worldDefinition, sceneryName) == EXIT_FAILURE)
	{
		std::cerr << "The world definition had not been loaded properly" << std::endl;
		return EXIT_FAILURE;
	}

	// World definition initialization
	_world.Initialize(worldDefinition);
	return EXIT_SUCCESS;
}

void df::Game::Step(void)
{
	// Launching Think process
	_world.Think(_inputListener);
	
	// Setting up the view
	ComputeActorView();
	_renderWindow.SetView(_actorViewDefinition.View);

	// Launchin Draw process
	_world.Draw(_renderWindow);
}

#define FREE_VIEW_NAVIGATION_STRENGTH_VALUE 80.f
#define FREE_VIEW_NAVIGATION_FRICTIONAL_COEF 0.1f
void df::Game::ComputeActorView(void)
{
	// Compute screen half size
	sf::Vector2f screenHalfSize(_renderWindow.GetWidth() * _actorViewDefinition.ZoomValue.getValue() / 2.f,  _renderWindow.GetHeight() * _actorViewDefinition.ZoomValue.getValue() / 2.f);

	// Determine the View mode
	if(_actorViewDefinition.targetedEntity != NULL)
	{
		// Tracking mode
	}
	else
	{
		float navigationStrenghtValue = FREE_VIEW_NAVIGATION_STRENGTH_VALUE * df::Context::getEllapsedTime();
		// Free mode
		if(_inputListener.getNavigateLeftIsPressed()) _actorViewDefinition.Velocity.X -= navigationStrenghtValue;
		if(_inputListener.getNavigateRightIsPressed()) _actorViewDefinition.Velocity.X += navigationStrenghtValue;
		if(_inputListener.getNavigateUpIsPressed()) _actorViewDefinition.Velocity.Y += navigationStrenghtValue;
		if(_inputListener.getNavigateDownIsPressed()) _actorViewDefinition.Velocity.Y -= navigationStrenghtValue;
		_actorViewDefinition.Velocity.X -= _actorViewDefinition.Velocity.X * FREE_VIEW_NAVIGATION_FRICTIONAL_COEF;
		_actorViewDefinition.Velocity.Y -= _actorViewDefinition.Velocity.Y * FREE_VIEW_NAVIGATION_FRICTIONAL_COEF;
	}
	
	// Check zoom inputs
	if(_inputListener.getZoomInIsPressed()) _actorViewDefinition.ZoomValue -= 0.5f;
	if(_inputListener.getZoomOutIsPressed()) _actorViewDefinition.ZoomValue += 0.5f;
	_actorViewDefinition.ZoomValue.Step(df::Context::getEllapsedTime());

	// Increase View position
	_actorViewDefinition.View.Move(_actorViewDefinition.Velocity.X, -_actorViewDefinition.Velocity.Y);

	// Setting view properties
	_actorViewDefinition.View.SetHalfSize(screenHalfSize);
}
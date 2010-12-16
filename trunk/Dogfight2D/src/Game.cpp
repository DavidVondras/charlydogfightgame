#include "Game.h"
#include "Context.h"

df::Game::Game(sf::RenderWindow &renderWindow):
_renderWindow(renderWindow) {}

df::Game::~Game(void){}

int df::Game::Initialize(std::string sceneryName)
{
	// Compute screen half size
	sf::Vector2f screenHalfSize(_renderWindow.GetWidth() / 2.f,  _renderWindow.GetHeight() / 2.f);

	// Actor view Initialization
	_gameViewDefinition.targetedEntity = NULL;
	_gameViewDefinition.Position.X.setValue(screenHalfSize.x);
	_gameViewDefinition.Position.Y.setValue(-screenHalfSize.y);
	_gameViewDefinition.Position.X.setVelocityCoefficient(10.f);
	_gameViewDefinition.Position.Y.setVelocityCoefficient(10.f);
	_gameViewDefinition.Zoom.setValue(1.f);
	_gameViewDefinition.Zoom.setErrorDelta(0.001f);
	_gameViewDefinition.Zoom.setVelocityCoefficient(20.f);

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
	_renderWindow.SetView(_gameViewDefinition.View);

	// Launchin Draw process
	_world.Draw(_renderWindow);
}

#define FREE_VIEW_NAVIGATION_STRENGTH_VALUE 800.f
void df::Game::ComputeActorView(void)
{
	// Compute screen half size
	sf::Vector2f screenHalfSize(
		_renderWindow.GetWidth() * _gameViewDefinition.Zoom.getValue() / 2.f,  
		_renderWindow.GetHeight() * _gameViewDefinition.Zoom.getValue() / 2.f);

	// Check zoom inputs
	if(_inputListener.getZoomInIsPressed()) _gameViewDefinition.Zoom -= 0.5f;
	if(_inputListener.getZoomOutIsPressed()) _gameViewDefinition.Zoom += 0.5f;
	_gameViewDefinition.Zoom.Step(df::Context::getEllapsedTime());

	// Check view mode inputs
	if(_inputListener.getCameraActorIsRequested()) _gameViewDefinition.targetedEntity = _world.getActor();
	if(_inputListener.getCameraFreeIsRequested()) _gameViewDefinition.targetedEntity = NULL;

	// Determine the View mode
	if(_gameViewDefinition.targetedEntity != NULL)
	{
		// Tracking mode
		sf::Vector2f &actorPosition = _gameViewDefinition.targetedEntity->_position.ToPixel();
		_gameViewDefinition.Position.X = actorPosition.x;
		_gameViewDefinition.Position.Y = actorPosition.y;
	}
	else
	{
		float navigationStrenghtValue = FREE_VIEW_NAVIGATION_STRENGTH_VALUE * df::Context::getEllapsedTime();
		// Free mode
		if(_inputListener.getNavigateLeftIsPressed()) _gameViewDefinition.Position.X -= navigationStrenghtValue;
		if(_inputListener.getNavigateRightIsPressed()) _gameViewDefinition.Position.X += navigationStrenghtValue;
		if(_inputListener.getNavigateUpIsPressed()) _gameViewDefinition.Position.Y -= navigationStrenghtValue;
		if(_inputListener.getNavigateDownIsPressed()) _gameViewDefinition.Position.Y += navigationStrenghtValue;
	}

	// View position update
	_gameViewDefinition.Step(df::Context::getEllapsedTime());

	// View size update
	_gameViewDefinition.View.SetHalfSize(screenHalfSize);
}
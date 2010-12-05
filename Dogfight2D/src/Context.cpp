#include "Context.h"

// Static fields initialization
float df::Context::_ellapsedTime = 0;

void df::Context::ExtractRenderWindowStatus(sf::RenderWindow const &renderWindow)
{
	_ellapsedTime = renderWindow.GetFrameTime();
}
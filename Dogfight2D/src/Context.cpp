#include "Context.h"

// Static fields initialization
float df::Context::_ellapsedTime = 0;
df::SizeStructInt df::Context::_windowSize = df::SizeStructInt();

void df::Context::ExtractRenderWindowStatus(sf::RenderWindow const &renderWindow)
{
	_ellapsedTime = renderWindow.GetFrameTime();
	_windowSize.Width = renderWindow.GetWidth();
	_windowSize.Height = renderWindow.GetHeight();
}
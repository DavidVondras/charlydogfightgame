#include "Context.h"

// Static fields initialization
float df::Context::_ellapsedTime = 0;
float df::Context::_frameRate = 0;
df::SizeStructInt df::Context::_windowSize = df::SizeStructInt();

void df::Context::ExtractRenderWindowStatus(sf::RenderWindow const &renderWindow)
{
	_ellapsedTime = renderWindow.GetFrameTime();
	_frameRate = 1.f/_ellapsedTime;
	_windowSize.Width = renderWindow.GetWidth();
	_windowSize.Height = renderWindow.GetHeight();
}

void df::Context::AddInPropertyListener(void)
{
	df::PropertyListener::getInstance().AddProperty(&_frameRate, "FPS: %.1f");
}
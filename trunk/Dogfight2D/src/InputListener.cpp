#include "InputListener.h"

df::InputListener::InputListener(void){}

df::InputListener::~InputListener(void){}

void df::InputListener::Listen(sf::RenderWindow &renderWindow)
{
	// Process events
    sf::Event inputEvent;
    while (renderWindow.GetEvent(inputEvent))
    {
		// Delegate event processing
        if (inputEvent.Type != sf::Event::Closed)
		{
			ProcessEvent(inputEvent, renderWindow);
		}
		// Close window : exit
		else
		{
            renderWindow.Close();
		}
    }
}
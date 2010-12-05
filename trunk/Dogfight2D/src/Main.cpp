#include <stdlib.h>
#include <iostream>
#include "Context.h"
#include "Game.h"

int main(void)
{
	// Begining of application
	std::cout<<"Application Started"<<std::endl;

	// sf instances
	sf::RenderWindow renderWindow(sf::VideoMode(800, 600, 32), "Dogfight");
	renderWindow.UseVerticalSync(true);
	renderWindow.SetFramerateLimit(60);
	df::Game game(renderWindow);
	game.Initialize("scene1");

	// Main loop
	while(renderWindow.IsOpened())
	{
		df::Context::ExtractRenderWindowStatus(renderWindow);
		game.getInputListener().Listen(renderWindow);
		renderWindow.Clear();
		game.Step();
		renderWindow.Display();
	};

	// End of application
	std::cout<<"Application Ended"<<std::endl;
	return EXIT_SUCCESS;
}

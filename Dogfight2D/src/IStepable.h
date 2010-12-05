#pragma once
#include <SFML\Graphics.hpp>
#include "InputListener.h"

namespace df
{
	class IStepable
	{
	public:
		virtual void Think(df::InputListener const &inputListner) = 0;
		virtual void Draw(sf::RenderWindow &renderWindow) = 0;
	};
}
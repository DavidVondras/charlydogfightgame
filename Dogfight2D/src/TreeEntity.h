#pragma once
#include "Entity.h"

namespace df
{
	class TreeEntity : public df::Entity
	{
	public:
		TreeEntity(void);
		~TreeEntity(void);

		void Think(df::InputListener const &inputListner);
		void Draw(sf::RenderWindow &renderWindow);
	};
}


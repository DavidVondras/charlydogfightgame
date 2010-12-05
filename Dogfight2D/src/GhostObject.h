#pragma once
#include "IStepable.h"

namespace df
{
	class GhostObject : 
		public df::IStepable
	{
	private:
		sf::Sprite _sprite;

	public:
		GhostObject(void);
		~GhostObject(void);

		void Think(df::InputListener const &inputListner);
		void Draw(sf::RenderWindow &renderWindow);
	};
}


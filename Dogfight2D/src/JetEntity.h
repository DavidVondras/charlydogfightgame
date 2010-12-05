#pragma once
#include "Entity.h"
#include "DogfightCore.h"

namespace df
{
	class JetEntity: public df::Entity
	{
	private:
		sf::Sprite _sprite;
		sf::Image _image;
		df::Point _position;

	public:
		JetEntity(void);
		~JetEntity(void);

		void Think(df::InputListener const &inputListner);
		void Draw(sf::RenderWindow &renderWindow);
	};
}


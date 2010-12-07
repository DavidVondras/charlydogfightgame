#pragma once
#include "IStepable.h"
#include "BoundableObject.h"
#include "DogfightCore.h"

namespace df
{
	class JetEntity: 
		public df::IStepable,
		public df::BoundableObject
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


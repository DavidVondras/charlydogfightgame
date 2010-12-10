#pragma once
#include "PhysicObject.h"
#include "DogfightCore.h"

namespace df
{
	class TreeEntity : 
		public df::PhysicObject
	{
	private:
		sf::Sprite _sprite;
		sf::Image _image;
		df::Point _position;

	public:
		TreeEntity(void);
		~TreeEntity(void);

		void RegisterToPhysicWorld(b2World &world);
		void Think(df::InputListener const &inputListner);
		void Draw(sf::RenderWindow &renderWindow);
	};
}


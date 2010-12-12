#pragma once
#include "PhysicObject.h"
#include "DogfightCore.h"

namespace df
{
	class JetEntity: 
		public df::PhysicObject
	{
	private:
		sf::Sprite _sprite;
		sf::Image _image;
		df::Point _position;
		float _rotation; // in radians

	public:
		JetEntity(void);
		~JetEntity(void);

		void RegisterToPhysicWorld(b2World &world);
		void Think(df::InputListener const &inputListner);
		void Draw(sf::RenderWindow &renderWindow);
	};
}


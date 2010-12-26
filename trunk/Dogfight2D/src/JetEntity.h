#pragma once
#include "PhysicObject.h"
#include "DogfightCore.h"
#include "PropertyListener.h"

namespace df
{
	class JetEntity: 
		public df::PhysicObject
	{
	private:
		sf::Sprite _sprite;
		sf::Image _image;
		float _engineValue;

	public:
		JetEntity(void);
		~JetEntity(void);

		void AddInPropertyListener(void);
		void RegisterToPhysicWorld(b2World &world);
		void Think(df::InputListener const &inputListner);
		void Draw(sf::RenderWindow &renderWindow);
	};
}


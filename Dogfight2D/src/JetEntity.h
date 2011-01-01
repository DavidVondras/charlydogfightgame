#pragma once
#include "PhysicObject.h"
#include "DogfightCore.h"
#include "PropertyListener.h"

#define CzVelocityMin 20.f
#define CzVelocityMax 150.f
#define Mass 1000.f
#define MassInertia 5000.f
#define EngineStrengthCoefficient 50000.f

namespace df
{
	class JetEntity: 
		public df::PhysicObject
	{
	private:
		sf::Sprite _sprite;
		sf::Image _image;
		float _engineValue;
		df::Point _localVelocity;
		float _normalVelocity;
		float _cz;

		// Debug info
		// These peaces of information are redundant with entity fields.
		// They are used to be referenced for debug needs.
		float  _debug_localVelocity_x, _debug_localVelocity_y;

	public:
		JetEntity(void);
		~JetEntity(void);

		void AddInPropertyListener(void);
		void RegisterToPhysicWorld(b2World &world);
		void Think(df::InputListener const &inputListner);
		void Draw(sf::RenderWindow &renderWindow);
	};
}


#pragma once
#include <stdlib.h>
#include <list>
#include <SFML\Graphics.hpp>
#include "ListHelper.h"

namespace df
{
	class PropertyListener
	{
	private:
		PropertyListener();
		~PropertyListener();

		enum PropertyWrapperType { floatType };
		struct PropertyWrapper
		{
			PropertyWrapper(float* propertyPtr, std::string stringFormat): 
			PropertyPtr(propertyPtr), StringFormat(stringFormat), PropertyType(floatType){}
		
			PropertyWrapperType PropertyType;
			void* PropertyPtr;
			std::string StringFormat;
		};

		std::list<PropertyWrapper*> _properties;

		// Instance of the singleton
		static PropertyListener* _instance;

	public:
		// Get the unique singleton instance
		static PropertyListener& getInstance(void)
		{
			if(_instance == NULL) _instance = new PropertyListener();
			return *_instance;
		}

		// Deletes the singleton instance
		static void DeleteInstance(void)
		{
			if(_instance != NULL)
			{
				df::ListHelper::ClearListPointer<PropertyWrapper>(_instance->_properties);
				delete _instance;
			}
			_instance = NULL;
		}

		void AddProperty(float* propertyPtr, const std::string stringFormat);
		void RemoveProperty(void* propertyPtr);
		void Draw(sf::RenderWindow& renderWindow);
	};
}
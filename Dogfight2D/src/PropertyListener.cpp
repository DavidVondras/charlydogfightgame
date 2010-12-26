#include "PropertyListener.h"
#include <iostream>

// static properties initialization
df::PropertyListener *df::PropertyListener::_instance = NULL;

df::PropertyListener::PropertyListener(){}
df::PropertyListener::~PropertyListener(){}

void df::PropertyListener::AddProperty(float* propertyPtr, const std::string stringFormat)
{
	_properties.push_back(new PropertyWrapper(propertyPtr, stringFormat));
}

void df::PropertyListener::RemoveProperty(void* propertyPtr)
{
	std::cerr<<"PropertyListener::RemoveProperty is not implemented yet!"<<std::endl;
}

void df::PropertyListener::Draw(sf::RenderWindow& renderWindow)
{
	int currentPosition = 5;
	char stringBuffer[256];
	sf::String stringRenderBuffer;
	stringRenderBuffer.SetColor(sf::Color::White);
	stringRenderBuffer.SetSize(14.f);
	foreach(PropertyWrapper*, _properties)
	{
		switch((*i)->PropertyType)
		{
		case floatType:
			sprintf_s(stringBuffer, (*i)->StringFormat.c_str(), *((float*)(*i)->PropertyPtr));
			break;
		default:
			strcpy_s(stringBuffer, "Type not found...");
		}
		stringRenderBuffer.SetText(stringBuffer);
		stringRenderBuffer.SetPosition(5.f, (float)currentPosition);
		renderWindow.Draw(stringRenderBuffer);
		currentPosition += 18;
	}
}
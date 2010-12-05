#pragma once
#include "InputListener.h"

namespace df
{
	class IScreen
	{
	public:
		virtual InputListener& getInputListener(void) = 0;
	};
}
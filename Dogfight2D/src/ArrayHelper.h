#pragma once
#include <stdlib.h>

namespace df
{
	class ArrayHelper
	{
	public:
		template<class T>
		static int Add(T arrayTarget[], T value, int &arrayCounter, int arrayMaxSize)
		{
			if(arrayCounter >= arrayMaxSize - 1)
			{
				return EXIT_FAILURE;
			}
			arrayTarget[arrayCounter++] = value;
			return EXIT_SUCCESS;
		}
	};
}
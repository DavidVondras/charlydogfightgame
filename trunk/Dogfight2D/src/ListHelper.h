#pragma once
#include <list>

#define foreach(type, listObject) \
	for(std::list<type>::iterator i = listObject.begin(); i != listObject.end(); i++)

namespace df
{
	class ListHelper
	{
	private:
		template<class T>
		static bool DeleteAllPointerIteration(T *element)
		{
			delete element;
			return true;
		}
	public:
		// Clears the list and delete all the pointer instances
		template<class T>
		static void ClearListPointer(std::list<T*> &list)
		{
			list.remove_if(DeleteAllPointerIteration<T>);
		}
	};
}
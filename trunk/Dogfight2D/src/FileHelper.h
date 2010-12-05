#pragma once
#include <sys/types.h>
#include <sys/stat.h>
#include <string>

namespace df
{
	class FileHelper
	{
	public:
		static int FolderExists(std::string folderName)
		{
			struct stat statInstance;
			return stat(folderName.c_str(), &statInstance) == 0;
		}
	};
}
#pragma once

namespace df
{
	struct SizeStruct
	{ 
		SizeStruct():Width(0.f), Height(0.f){}
		SizeStruct(const float &x, const float &y):Width(x), Height(y){} 
		float Width, Height; 
	};

	struct SizeStructInt
	{ 
		SizeStructInt():Width(0), Height(0){}
		SizeStructInt(const int &x, const int &y):Width(x), Height(y){} 
		int Width, Height; 
	};
}
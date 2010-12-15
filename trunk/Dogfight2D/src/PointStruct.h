#pragma once

namespace df
{
	struct PointStruct
	{ 
		PointStruct():X(0.f), Y(0.f){}
		PointStruct(const float &x, const float &y):X(x), Y(y){} 
		float X, Y; 
	};
}
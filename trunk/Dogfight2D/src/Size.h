#pragma once

namespace df
{
	// Size definition
	struct Size
	{
		Size() : Width(0.f), Height(0.f) {}
		Size(float width, float height) : Width(width), Height(height) {}
		float Width;
		float Height;
	};
}
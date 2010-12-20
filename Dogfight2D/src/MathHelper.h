#pragma once

namespace df
{
	class MathHelper
	{
	public:
		static float PolyBezier(float x, float xa, float ya, float xb, float yb)
		{
			if(x <= xa) return ya;
			if(x >= xb) return yb;

			float xa_2 = xa*xa;
			float xa_3 = xa_2*xa;
			float xb_2 = xb*xb;
			float xb_3 = xb_2*xb;
			float x_2 = x*x;
			float x_3 = x_2*x;

			return 
				// TODO: Optimize formula
				(3.f*xa_2*xb*yb-xa_3*yb+(xb_3-3.f*xa*xb)*ya + (6.f*x*xa*xb - 3.f*x_2*(xb+xa)+2.f*x_3)*(ya-yb))
				/ (xb_3-3.f*xa*xb_2+3.f*xa_2*xb-xa_3);
		}
	};
}
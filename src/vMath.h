#pragma once

namespace m3d
{
	constexpr double M_PI = 3.14159265358979323846264338327950288;

	inline double toRadians(double degrees)
	{
		return (degrees * (M_PI / 180.0f));
	}
}


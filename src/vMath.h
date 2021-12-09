#pragma once

namespace m3d
{
	template<typename T>
	struct PI
	{
		constexpr static T value = static_cast<T>(3.14159265358979323846264338327950288);
	};
	
	template<typename T>
	inline constexpr T pi_v = PI<T>::value;

	template<typename T>
	inline double toRadians(T degrees)
	{
		return (degrees * (pi_v<T> / static_cast<T>(180)));
	}
}

